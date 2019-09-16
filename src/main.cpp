#include <iostream>

#include "antlr4-runtime.h"
#include "brill.h"

using namespace std;

int main(int argc, const char *argv[]) {
    if (!argv[1]) {
        printf("You must specify a file to use\n");
        return 0;
    }

    printf("Parsing: %s\n", argv[1]);

    Brill::BrillParser::TopLevelContext *file = Brill::parseFile(argv[1]);
    printf("got expression\n");
    Brill::ParseTreeListener listener;
    printf("got walker\n");
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, file);
    printf("finished\n");

    return 0;
}