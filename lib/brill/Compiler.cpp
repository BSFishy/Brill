#include "brill/Compiler.h"
#include "brill/Diagnostics/DiagnosticsEngine.h"

using namespace Brill;

// Compiler::Compiler() : sourceManager(), diagnosticsEngine() {}
// Compiler::Compiler(SourceManager &sourceManager, Diagnostics::DiagnosticsEngine &diagnosticsEngine) :
//     sourceManager(sourceManager), diagnosticsEngine(diagnosticsEngine) {}

Compiler::Compiler() {
    sourceManager = SourceManager::get();
    diagnosticsEngine = Diagnostics::DiagnosticsEngine::get();
}

Compiler Compiler::create(CompilerOptions options) {
    Compiler compiler;
    compiler.options = options;
    return compiler;
}

const Diagnostics::DiagnosticsEngine &Compiler::getDiagnosticsEngine() const {
    return *(this->diagnosticsEngine);
}