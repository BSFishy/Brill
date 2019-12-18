#pragma once

#include "Diagnostic.h"

namespace Brill::Diagnostics {
    /// This struct handles diagnostics.
    ///
    /// Different events during the compilation process can be
    /// given to this engine, and it will form the information
    /// into properly formed information messages to be printed
    /// to the console.
    struct DiagnosticsEngine {
    public:
        // DiagnosticsEngine() = default;
        
        static DiagnosticsEngine *get();

        void report();
    };
}