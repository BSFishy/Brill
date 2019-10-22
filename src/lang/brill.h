
#pragma once

#include <istream>
#include <memory>

#include "BrillParser.h"
#include "BrillLexer.h"

// #include "compiler.h"
// #include "codegen/codegen.h"

// #include "lang/bir/bir.h"
// #include "ast/ast.h"

namespace Brill {
    struct ParseContext {
        BrillParser::TopLevelContext *topLevel;

        std::shared_ptr<antlr4::ANTLRInputStream> input;
        std::shared_ptr<BrillLexer> lexer;
        std::shared_ptr<antlr4::CommonTokenStream> tokens;
        std::shared_ptr<BrillParser> parser;

        explicit ParseContext(BrillParser::TopLevelContext* t, std::shared_ptr<antlr4::ANTLRInputStream> i, std::shared_ptr<BrillLexer> l, std::shared_ptr<antlr4::CommonTokenStream> to, std::shared_ptr<BrillParser> p) : topLevel(std::move(t)), input(std::move(i)), lexer(std::move(l)), tokens(std::move(to)), parser(std::move(p)) {}
    };

    /**
     * Parse the given input stream and return the toplevel context to do things with.
     *
     * @param stream The stream to parse
     * @return the toplevel context
     */
    std::shared_ptr<ParseContext> parse(std::istream &stream);

    /**
     * Parse the given source code and return the toplevel context to do things with.
     *
     * @return the toplevel context
     */
    std::shared_ptr<ParseContext> parse(const char *);

    /**
     * Parse the given file and return the toplevel context to do things with.
     * @return the toplevel context
     */
    std::shared_ptr<ParseContext> parseFile(const char *);

    /**
     * work in progress
     * @param stream
     */
    void compile(std::istream &stream);

    /**
     * work in progress
     */
    void compile(const char *);

    /**
     * work in progress
     */
    void compileFile(const char *);

    /**
     * work in progress
     */
    void compile(BrillParser::TopLevelContext *);
}
