#include <ostream>
#include <string>
#include "llvm/Support/CommandLine.h"
#include "brill_version.h"

using namespace llvm;

cl::OptionCategory brillCat("Compiler options", "Options that are usefull when copmiling Brill files");

cl::list<std::string> input(cl::Positional, cl::desc("<input files>"), cl::OneOrMore, cl::cat(brillCat));

int main(int argc, const char *argv[]) {
    cl::HideUnrelatedOptions(brillCat);
    cl::SetVersionPrinter([](raw_ostream &out) {
        out << "Brill " << BONES_VERSION << "\n";
        out << "LLVM " << LLVM_VERSION << "\n";
    });

    cl::ParseCommandLineOptions(argc, argv, "Brill Compiler\n", &errs(), nullptr, true);

    outs() << "Inputted files:" << "\n";
    for (auto const& file : input) {
        outs() << "\t" << file << "\n";
    }
}