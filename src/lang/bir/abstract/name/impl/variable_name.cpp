
#include "variable_name.h"

#include "not_implemented_exception.h"

std::string Brill::IR::VariableName::stringValue() {
    std::string result;
    if (this->parent.has_value()) {
        result = this->parent.value().stringValue() + ".";
    }

    result += this->name;
    return result;
}

Brill::IR::mangled_name Brill::IR::VariableName::mangle() {
    throw NotImplementedException();
}

Brill::IR::demangled_name Brill::IR::VariableName::demangle(Brill::IR::mangled_name) {
    throw NotImplementedException();
}
