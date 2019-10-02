
#include <iostream>
#include <memory>

#include "brill.h"
#include "BrillParser.h"

using namespace std;

int main(int argc, const char *argv[]) {
    if (!argv[1]) {
        printf("You must specify a file to use\n");
        return 0;
    }

    fprintf(stderr, "Compiling: %s\n", argv[1]);

    std::shared_ptr<Brill::ParseContext> file = Brill::parseFile(argv[1]);
    shared_ptr<Brill::IR::CodegenContext> ctx = Brill::convert(file->topLevel);

    return 0;
}