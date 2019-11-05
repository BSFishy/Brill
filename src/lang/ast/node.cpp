
#include "node.h"

using namespace Brill::AST;

Node::Node() {
    this->symbolTable = std::make_shared<SymbolTable>();
}

Node::Node(const std::shared_ptr<SymbolTable> &s) {
    this->symbolTable = s;
}

std::shared_ptr<SymbolTable> Node::getSymbolTable() const {
    return this->symbolTable;
}
