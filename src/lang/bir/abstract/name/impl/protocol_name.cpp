
#include "protocol_name.h"

#include "not_implemented_exception.h"

std::string Brill::IR::ProtocolName::stringValue() {
    std::string result;
    if (this->parent.has_value()) {
        result = this->parent.value().stringValue() + ".";
    }

    result += this->name;
    return result;
}

Brill::IR::mangled_name Brill::IR::ProtocolName::mangle() {
    throw NotImplementedException();
}

Brill::IR::demangled_name Brill::IR::ProtocolName::demangle(Brill::IR::mangled_name) {
    throw NotImplementedException();
}
