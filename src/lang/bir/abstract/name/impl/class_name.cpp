
#include "class_name.h"

#include "not_implemented_exception.h"

std::string Brill::IR::ClassName::stringValue() {
    std::string result;
    if (this->parent) {
        result = this->parent->stringValue() + ".";
    }

    result += this->name;
    return result;
}

Brill::IR::mangled_name Brill::IR::ClassName::mangle() {
    throw NotImplementedException();
}

Brill::IR::demangled_name Brill::IR::ClassName::demangle(Brill::IR::mangled_name) {
    throw NotImplementedException();
}
