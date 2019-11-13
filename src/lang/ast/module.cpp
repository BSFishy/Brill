
#include "module.h"

#include "llvm/Support/raw_ostream.h"

#include "function/function.h"

#include "named_node.h"
#include "symbol_table.h"
#include "abstract/convert_context.h"
#include "abstract/codegen_context.h"

#include "util.h"

using namespace Brill::AST;

Module::Module(const std::string &name) : NamedNode(name) {}
Module::Module(const std::string &n, const std::shared_ptr<Module> &p) : NamedNode(n), Node(p->getSymbolTable()->child()) {
    this->parent = p;
}

std::string Module::getMangledName() const {
    // If the module name is anonymous and there is no parent, just return the prefix
    if (this->getName().length() == 0 && !(this->parent)) return MANGLER_PREFIX;

    std::string name;
    llvm::raw_string_ostream mangledName(name);
    if (this->getName().length() != 0) mangledName << "m" << this->getName().length() << this->getName();

    std::string prefix;
    if (this->parent) {
        prefix = this->parent->getMangledName();
    } else {
        prefix = MANGLER_PREFIX;
    }

    return prefix + mangledName.str();
}

llvm::Value *Module::codegen(std::shared_ptr<CodegenContext> ctx) const {
    this->codegenFunctions(ctx);

    return nullptr;
}

std::shared_ptr<Brill::AST::CodegenContext> Module::codegen(std::string moduleId) const {
    std::shared_ptr<CodegenContext> ctx = std::make_shared<CodegenContext>(moduleId);

    this->codegen(ctx);

    return ctx;
}

std::shared_ptr<Module> Brill::AST::convert(const std::shared_ptr<ConvertContext> &ccontext, BrillParser::TopLevelContext *ctx) {
    std::shared_ptr<Module> module = getOrCreateModule(ccontext->moduleName);
    std::shared_ptr<ConvertContext> cctx = ccontext->withParent(module);

    for(BrillParser::DeclarationContext *declaration : ctx->declarations()->declaration()) {
        if (BrillParser::FunctionDeclarationContext *functionContext = declaration->functionDeclaration()) {
            if (std::shared_ptr<Function> function = convert(cctx, functionContext)) {
                module->addFunction(function);
            } else {
                throw IllegalStateException("Unable to convert function");
            }
        } else {
            throw NotImplementedException();
        }
    }

    return module;
}

static std::vector<std::shared_ptr<Module>> modules;

void Brill::AST::addModule(const std::shared_ptr<Module> &module) {
    modules.push_back(module);
}

std::shared_ptr<Module> Brill::AST::getModule(const std::string &name) {
    for (std::shared_ptr<Module> const& module : modules) {
        if (module->getName() == name) {
            return module;
        }
    }

    return nullptr;
}

std::shared_ptr<Module> Brill::AST::getOrCreateModule(const std::string &name) {
    if (std::shared_ptr<Module> module = Brill::AST::getModule(name)) {
        return module;
    }

    std::shared_ptr<Module> module = std::make_shared<Module>(name);
    addModule(module);
    return module;
}

bool Brill::AST::removeModule(const std::string &name) {
    for (auto i = modules.begin(); i != modules.end(); ++i) {
        if ((*i)->getName() == name) {
            modules.erase(i);
            return true;
        }
    }

    return false;
}
