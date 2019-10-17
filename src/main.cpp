
#include <iostream>
#include <memory>

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCObjectFileInfo.h"

#include "brill.h"

using namespace std;

int main(int argc, const char *argv[]) {
    if (!argv[1]) {
        printf("You must specify a file to use\n");
        return 0;
    }

    fprintf(stderr, "Compiling: %s\n\n", argv[1]);

    std::shared_ptr<Brill::ParseContext> file = Brill::parseFile(argv[1]);
    Brill::convert(file->topLevel);

    std::shared_ptr<Brill::IR::Module> module = Brill::getOrCreateModule("test");
    std::shared_ptr<Brill::IR::CodegenContext> ctx = module->codegen();

    fprintf(stderr, "Output:\n\n");
    ctx->module->print(llvm::errs(), nullptr);

    // EMIT FILE STUFF

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    auto targetTriple = llvm::sys::getDefaultTargetTriple();
    ctx->module->setTargetTriple(targetTriple);

    std::string error;
    auto target = llvm::TargetRegistry::lookupTarget(targetTriple, error);

    if (!target) {
        fprintf(stderr, "%s\n", error.c_str());
        return 1;
    }

    auto cpu = "generic";
    auto features = "";

    llvm::TargetOptions opt;
    auto rm = llvm::Optional<llvm::Reloc::Model>();
    auto targetMachine = target->createTargetMachine(targetTriple, cpu, features, opt, rm);

    ctx->module->setDataLayout(targetMachine->createDataLayout());

    auto filename = "output.o";
    std::error_code ec;
    llvm::raw_fd_ostream dest(filename, ec, llvm::sys::fs::OF_None);

    if (ec) {
        fprintf(stderr, "Could not open file: %s\n", ec.message().c_str());
        return 1;
    }

    llvm::legacy::PassManager pass;
    auto fileType = llvm::TargetMachine::CGFT_ObjectFile;

    if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, fileType)) {
        fprintf(stderr, "Emitting to a file is not supported\n");
        return 1;
    }

    pass.run(*(ctx->module));
    dest.flush();

    fprintf(stderr, "\n\nWrote file %s\n", filename);

    return 0;
}