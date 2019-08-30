FROM gitpod/workspace-full

USER root

# Add llvm stuff
RUN curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
  && apt-add-repository -yu "deb http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main" \
  && sudo sh -c "echo deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main \ >> /etc/apt/sources.list"

# LLVM
RUN sudo apt-get install -yq libllvm-9-ocaml-dev libllvm9 llvm-9 llvm-9-dev llvm-9-doc llvm-9-examples llvm-9-runtime \
  && sudo rm -rf /var/lib/apt/lists/*

# CLang
RUN sudo apt-get install -yq clang-9 clang-tools-9 clang-9-doc libclang-common-9-dev libclang-9-dev libclang1-9 clang-format-9 python-clang-9 clangd-9 \
  && sudo rm -rf /var/lib/apt/lists/*

# LibFuzzer
RUN sudo apt-get install -yq libfuzzer-9-dev \
  && sudo rm -rf /var/lib/apt/lists/*

# LLDB
RUN sudo apt-get install -yq lldb-9 \
  && sudo rm -rf /var/lib/apt/lists/*

# LLD
RUN sudo apt-get install -yq lld-9 \
  && sudo rm -rf /var/lib/apt/lists/*

# LibC++
RUN sudo apt-get install -yq libc++-9-dev libc++abi-9-dev \
  && sudo rm -rf /var/lib/apt/lists/*

# Ninja
RUN sudo apt-get update \
 && sudo apt-get install -yq \
    ninja-build \
    #libllvm9 llvm-9 llvm-9-doc llvm-9-tools llvm-9-dev llvm-9-runtime clang-9 clang-tools-9 clang-9-doc libclang-common-9-dev libclang-9-dev libclang1-9 clang-format-9 libfuzzer-9-dev lld-9 libc++-9-dev libc++abi-9-dev \
 && sudo rm -rf /var/lib/apt/lists/*
