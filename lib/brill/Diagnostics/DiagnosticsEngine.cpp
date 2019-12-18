#include "brill/Diagnostics/DiagnosticsEngine.h"

using namespace Brill;

// Diagnostics::DiagnosticsEngine::DiagnosticsEngine() {}

Diagnostics::DiagnosticsEngine *Diagnostics::DiagnosticsEngine::get() {
    return new DiagnosticsEngine();
}
