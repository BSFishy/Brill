
#pragma once

#include <vector>
#include <string>
#include <memory>

namespace Brill::AST {
    class NamedNode;

    /**
     * A table of named nodes. This is basically a wrapper around a vector with a couple of helper
     * methods. Mainly, findFirst and findAll compare the node's names to the provided string
     * so that a node can be found by name.
     */
    class SymbolTable : public std::enable_shared_from_this<SymbolTable> {
        std::vector<std::shared_ptr<NamedNode>> symbols;
        std::shared_ptr<const SymbolTable> parent;
    public:
        SymbolTable();
        explicit SymbolTable(const std::shared_ptr<const SymbolTable>&);

        /**
         * Find the first node with the given name. This will perform a linear search through the
         * vector, and the first node with the provided name will be returned. If nothing in this
         * table is found and there is a parent table, the parent table will be searched for the
         * same name. Otherwise, a nullptr is returned.
         */
        std::shared_ptr<NamedNode> findFirst(const std::string&) const;
        /**
         * Find all of the nodes with the given name. This will perform a linear search through the
         * vector and add all nodes with a matching name to a new vector. The parent will then be searched,
         * if one exists, and the results of that will be added to the result.
         */
        std::vector<std::shared_ptr<NamedNode>> findAll(const std::string&) const;

        /**
         * Add a node to the table. This will do a simple push_back on the vector with the given node.
         */
        void add(const std::shared_ptr<NamedNode>&);
        /**
         * Remove a node from the table. This will traverse through the vector linearly and the first
         * match will be erased and the result of that operation will be returned.
         */
        bool remove(const std::shared_ptr<NamedNode>&);
        /**
         * Create a child symbol table. This will create a new symbol table, setting its parent to this
         * symbol table. This is usefull when going into a new scope so that the child has access to the
         * nodes in this table, but this table doesn't have access to the nodes in the child.
         */
        std::shared_ptr<SymbolTable> child() const;

        /**
         * Get the parent symbol table. This will simply return the value of the parent field of this
         * class, which is null if no parent is defined.
         */
        std::shared_ptr<const SymbolTable> getParent() const;

        /**
         * Get the number of symbols in this tree. This simply returns the size method of the vector
         * and doesn't take into account a parent symbol tree. It can be used to iterate through the
         * table, but doesn't include parent values.
         */
        //int size() const;
        /**
         * Get a node at the
         */
        //std::shared_ptr<NamedNode> get(int) const;
    };
}
