FROM gitpod/workspace-full

USER root

RUN sudo apt-get update \
 && sudo apt-get install -yq \
    ninja-build \
    clang-format clang-tidy clang-tools clang clangd libc++-dev libc++1 libc++abi-dev libc++abi1 libclang-dev libclang1 liblldb-dev libllvm-ocaml-dev libomp-dev libomp5 lld lldb llvm-dev llvm-runtime llvm python-clang \
 && sudo rm -rf /var/lib/apt/lists/*
