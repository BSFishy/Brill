
#include "function_name.h"

#include "not_implemented_exception.h"

std::string Brill::IR::FunctionName::stringValue() {
    std::string result;
    if (this->parent.has_value()) {
        result = this->parent.value().stringValue() + ".";
    }

    result += this->name;
    return result;
}

Brill::IR::mangled_name Brill::IR::FunctionName::mangle() {
    throw NotImplementedException();
}

Brill::IR::demangled_name Brill::IR::FunctionName::demangle(Brill::IR::mangled_name) {
    throw NotImplementedException();
}
