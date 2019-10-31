
#include "module.h"

#include "function/function.h"

#include "util.h"

using namespace Brill::AST;

llvm::Value *Module::codegen(std::shared_ptr<CodegenContext> ctx) {
    this->codegenFunctions(ctx);

    return nullptr;
}

std::shared_ptr<Brill::AST::CodegenContext> Module::codegen() {
    const char *filename = "placeholder";
    std::shared_ptr<llvm::LLVMContext> llvmContext = std::make_shared<llvm::LLVMContext>();
    std::shared_ptr<llvm::Module>      module      = std::make_shared<llvm::Module>(filename, *llvmContext);
    std::shared_ptr<llvm::IRBuilder<>> builder     = std::make_shared<llvm::IRBuilder<>>(*llvmContext);

    module->setSourceFileName(filename);
    std::shared_ptr<CodegenContext> ctx(new CodegenContext(llvmContext, module, builder));

    this->codegen(ctx);

    return ctx;
}

std::shared_ptr<Module> Brill::AST::convert(std::shared_ptr<ConvertContext> ccontext, BrillParser::TopLevelContext *ctx) {
    std::shared_ptr<Module> module = getOrCreateModule(ccontext->moduleName);
    std::shared_ptr<ConvertContext> cctx = ccontext->withParent(module.get());

    for(BrillParser::DeclarationContext *declaration : ctx->declarations()->declaration()) {
        if (BrillParser::FunctionDeclarationContext *functionContext = declaration->functionDeclaration()) {
            if (std::shared_ptr<Function> function = convert(cctx, functionContext)) {
                module->addFunction(function);
            } else {
                throw IllegalStateException("Unable to convert function");
            }
        } else {
            throw NotImplementedException();
        }
    }

    return module;
}

void Brill::AST::addModule(const std::shared_ptr<Module> &module) {
    Brill::AST::modules.push_back(module);
}

std::shared_ptr<Module> Brill::AST::getModule(const std::string &name) {
    for (std::shared_ptr<Module> const& module : Brill::AST::modules) {
        if (module->name == name) {
            return module;
        }
    }

    return nullptr;
}

std::shared_ptr<Module> Brill::AST::getOrCreateModule(const std::string &name) {
    if (std::shared_ptr<Module> module = Brill::AST::getModule(name)) {
        return module;
    }

    return std::make_shared<Module>(name);
}

bool Brill::AST::removeModule(const std::string &name) {
    for (auto i = Brill::AST::modules.begin(); i != Brill::AST::modules.end(); ++i) {
        if ((*i)->name == name) {
            Brill::AST::modules.erase(i);
            return true;
        }
    }

    return false;
}
