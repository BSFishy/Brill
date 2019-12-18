#pragma once

#include "llvm/ADT/PointerUnion.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/MemoryBuffer.h"
#include <vector>

namespace Brill {
    struct SourceLocation;
    struct SourceRange;

    /// A structure that manages source files.
    ///
    /// This will load all necessary files into memory and provide
    /// locational offsets for specific positions in the source files.
    /// This uses MemoryBuffers provided by LLVM, and the offsets are
    /// simply just the index in the buffer.
    struct SourceManager {
    private:
        std::vector<llvm::MemoryBuffer> buffers;

        // friend struct Compiler;
        // SourceManager() = default;
    public:
        // SourceManager(const SourceManager&) = delete;
        // SourceManager &operator=(const SourceManager&) = delete;
        // SourceManager(SourceManager&&) = default;
        // SourceManager &operator=(SourceManager&&) = default;

        static SourceManager *get();

        bool addFile(llvm::StringRef);
    };

    /// A location in source code.
    ///
    /// This structure is simply an offset to some position in a source file.
    /// The files are managed by a SourceManager, and this structure can be
    /// used to find some character in one of the buffers.
    ///
    /// This structure also caches some simple values, such as the line and
    /// column of the location.
    ///
    /// This structure cannot be directly instantiated. It must be created from
    /// a SourceManager, so that we can make sure all locations contain the necessary
    /// and point to valid positions.
    struct SourceLocation {
    private:
        const char *Ptr = nullptr;

        unsigned line = -1;
        unsigned column = -1;

        SourceLocation() = default;
        friend SourceManager;
    public:
        SourceLocation(const SourceLocation&) = default;
        SourceLocation &operator=(const SourceLocation&) = default;
        SourceLocation(SourceLocation&&) = default;
        SourceLocation &operator=(SourceLocation&&) = default;

        bool isValid() { return Ptr != nullptr; }

        bool operator==(const SourceLocation &rhs) const { return rhs.Ptr == Ptr; }
        bool operator!=(const SourceLocation &rhs) const { return rhs.Ptr != Ptr; }

        const char *getPtr() const { return Ptr; }
        unsigned getLine() const { return line; }
        unsigned getColumn() const { return column; }
    };

    /// A range of characters in source code.
    ///
    /// This contains two locations to represent the beginning
    /// and end of the range.
    ///
    /// This structure cannot be directly instantiated. It must be created from
    /// a SourceManager, so that we can make sure all locations contain the necessary
    /// and point to valid positions.
    struct SourceRange {
    private:
        SourceLocation begin, end;

        SourceRange(const SourceLocation &begin, const SourceLocation &end) : begin(begin), end(end) {}
        friend SourceManager;
    public:
        SourceRange(const SourceRange&) = default;
        SourceRange &operator=(const SourceRange&) = default;
        SourceRange(SourceRange&&) = default;
        SourceRange &operator=(SourceRange&&) = default;

        const SourceLocation& getBegin() const { return begin; }
        const SourceLocation& getEnd() const { return end; }

        size_t getSize() const { return begin.getPtr() - end.getPtr(); }
    };
}