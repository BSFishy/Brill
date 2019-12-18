#pragma once

#include "CompilerOptions.h"
#include "SourceManager.h"
#include "Diagnostics/DiagnosticsEngine.h"

namespace Brill {
    /// This is an abstract representation of a compiler.
    ///
    /// This will handle everything from source files, diagnostics,
    /// and whatever other resources a compiler might use.
    ///
    /// Because this class handles everything related to the compiler,
    /// only one should be made per compilation job. If multiple
    /// jobs are being run, possibly in parallel, multiple objects
    /// can be created, but if there is only one job, only create one.
    struct Compiler {
    private:
        SourceManager *sourceManager;
        Diagnostics::DiagnosticsEngine *diagnosticsEngine;

        CompilerOptions options;

        // Compiler() = default;
        Compiler();
    public:
        static Compiler create(CompilerOptions);

        const Diagnostics::DiagnosticsEngine &getDiagnosticsEngine() const;

        void parse();
        void generateAST();
        void compile();
    };
}