
#include "named_node.h"

using namespace Brill::AST;

NamedNode::NamedNode(std::string n) : Node(), name(std::move(n)) {}

std::string NamedNode::getName() const {
    return this->name;
}
