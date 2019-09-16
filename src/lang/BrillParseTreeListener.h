
#pragma once

#include "BrillBaseListener.h"

namespace Brill {
    class ParseTreeListener : public BrillBaseListener {
    public:
        void enterTopLevel(BrillParser::TopLevelContext *) override;
        void exitTopLevel(BrillParser::TopLevelContext *) override;
    };
}
