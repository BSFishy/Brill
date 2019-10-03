
#pragma once

#include <vector>
#include <memory>

#include "module.h"

namespace Brill {
    static std::vector<std::shared_ptr<IR::Module>> modules;

    void addModule(const std::shared_ptr<IR::Module>&);

    std::shared_ptr<IR::Module> getModule(const std::string&);
    std::shared_ptr<IR::Module> getOrCreateModule(const std::string&);
}
