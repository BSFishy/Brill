
#include "class_container.h"
#include "tree/constructs/class/class.h"

using namespace Brill::IR;

void ClassContainer::addClass(const std::shared_ptr<Class> &c) {
    this->classes.push_back(c);
}

std::shared_ptr<Class> ClassContainer::getClass(const std::string &name) {
    for (std::shared_ptr<Class> const& c : this->classes) {
        if (c->name == name) {
            return c;
        }
    }

    return nullptr;
}

size_t ClassContainer::classCount() {
    return this->classes.size();
}
