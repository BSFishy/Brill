
#include "modules.h"

using namespace Brill;

void Brill::addModule(const std::shared_ptr<IR::Module> &module) {
    Brill::modules.push_back(module);
}

std::shared_ptr<IR::Module> Brill::getModule(const std::string &name) {
    for (std::shared_ptr<IR::Module> const& m : Brill::modules) {
        if (m->name == name) {
            return m;
        }
    }

    return nullptr;
}

std::shared_ptr<IR::Module> Brill::getOrCreateModule(const std::string &name) {
    if (std::shared_ptr<IR::Module> module = getModule(name)) {
        return module;
    }

    std::shared_ptr<IR::Module> module(new IR::Module(name));
    addModule(module);

    return module;
}
