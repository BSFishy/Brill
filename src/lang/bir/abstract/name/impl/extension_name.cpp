
#include "extension_name.h"

#include "not_implemented_exception.h"

std::string Brill::IR::ExtensionName::stringValue() {
    std::string result;
    if (this->parent.has_value()) {
        result = this->parent.value().stringValue() + ".";
    }

    result += this->name;
    return result;
}

Brill::IR::mangled_name Brill::IR::ExtensionName::mangle() {
    throw NotImplementedException();
}

Brill::IR::demangled_name Brill::IR::ExtensionName::demangle(Brill::IR::mangled_name) {
    throw NotImplementedException();
}
