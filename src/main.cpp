#include <cstdio>

#include "antlr4-runtime.h"
#include "lang/brill.h"

using namespace std;

int main(int argc, const char *argv[]) {
    if (!argv[1]) {
        printf("You must specify a file to use\n");
        return 0;
    }

    printf("Parsing: %s\n", argv[1]);

    antlr4::tree::ParseTree *expr = Brill::parseFile(argv[1]);
    if (expr) {
        printf("Expression: %s\n", expr->toStringTree().c_str());
    } else {
        printf("Could not parse file\n");
        return 1;
    }

    return 0;
}