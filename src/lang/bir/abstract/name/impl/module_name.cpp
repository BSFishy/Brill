
#include "module_name.h"
#include "not_implemented_exception.h"

Brill::IR::ModuleName::ModuleName(std::string name) {
    this->name = std::move(name);
}

std::string Brill::IR::ModuleName::stringValue() {
    return this->name;
}

Brill::IR::mangled_name Brill::IR::ModuleName::mangle() {
    throw NotImplementedException();
}

Brill::IR::demangled_name Brill::IR::ModuleName::demangle(Brill::IR::mangled_name) {
    throw NotImplementedException();
}
