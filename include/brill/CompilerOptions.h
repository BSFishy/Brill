#pragma once

namespace Brill {
    /// This is a simple storage object to contain compiler options.
    ///
    /// All this is meant to do is allow external tools to pass
    /// some options to the Brill compiler using a simple and easy
    /// to use format.
    struct CompilerOptions {
        const char *moduleName;

        const char *files[];
    };
}