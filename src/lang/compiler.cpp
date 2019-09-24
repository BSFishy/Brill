
#include "brill.h"

using namespace Brill;

CompileContext *Brill::Compiler::createContext(const char * name) {
    return new CompileContext(name);
}
