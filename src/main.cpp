#include <iostream>

#include "brill.h"

using namespace std;

int main(int argc, const char *argv[]) {
    if (!argv[1]) {
        printf("You must specify a file to use\n");
        return 0;
    }

    printf("Compiling: %s\n", argv[1]);

    Brill::BrillParser::TopLevelContext *file = Brill::parseFile(argv[1]);

    return 0;
}