
#pragma once

#include <istream>
#include "BrillParser.h"
#include "BrillLexer.h"
#include "compiler.h"
#include "codegen/codegen.h"

namespace Brill {
    /**
     * Parse the given input stream and return the toplevel context to do things with.
     *
     * @param stream The stream to parse
     * @return the toplevel context
     */
    Brill::BrillParser::TopLevelContext *parse(std::istream &stream);

    /**
     * Parse the given source code and return the toplevel context to do things with.
     *
     * @return the toplevel context
     */
    Brill::BrillParser::TopLevelContext *parse(const char *);

    /**
     * Parse the given file and return the toplevel context to do things with.
     * @return the toplevel context
     */
    Brill::BrillParser::TopLevelContext *parseFile(const char *);

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
    void compile(Brill::BrillParser::TopLevelContext *);
}
