
#pragma once

#include <stdexcept>
#include <string>

class IllegalStateException : public std::logic_error {
public:
    IllegalStateException() : std::logic_error("Illegal state") {};
    explicit IllegalStateException(const std::string& message) : std::logic_error("Illegal state: " + message) {};
};
