
#include "module_name.h"
#include "not_implemented_exception.h"

std::string Brill::IR::ModuleName::stringValue() {
    std::string result;
    if (this->parent) {
        result = this->parent->stringValue() + ".";
    }

    result += this->name;
    return result;
}

Brill::IR::mangled_name Brill::IR::ModuleName::mangle() {
    throw NotImplementedException();
}

Brill::IR::demangled_name Brill::IR::ModuleName::demangle(Brill::IR::mangled_name) {
    throw NotImplementedException();
}
