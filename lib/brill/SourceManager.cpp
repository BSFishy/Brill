#include "brill/SourceManager.h"

using namespace Brill;

// SourceManager::SourceManager() {}

SourceManager *SourceManager::get() {
    return new SourceManager();
}
