#pragma once

#include "BrillBaseVisitor.h"

namespace Brill::AST {
    class ParseTreeVisitor : public BrillBaseVisitor {
    public:
        virtual antlrcpp::Any visitTopLevel(BrillParser::TopLevelContext *ctx) override;
    };
}