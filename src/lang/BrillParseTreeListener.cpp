
#include <iostream>
#include "BrillParseTreeListener.h"

using namespace Brill;

void ParseTreeListener::enterTopLevel(BrillParser::TopLevelContext * ctx) {
    printf("entered top level\n");
}

void ParseTreeListener::exitTopLevel(BrillParser::TopLevelContext *) {
    printf("exited top level\n");
}
