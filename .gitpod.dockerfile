FROM gitpod/workspace-full

USER root

RUN sudo sh -c "echo deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main \ >> /etc/apt/sources.list"

RUN sudo apt-get update \
 && sudo apt-get install -yq \
    ninja-build \
    libllvm9 llvm-9 llvm-9-doc llvm-9-tools llvm-9-dev llvm-9-runtime clang-9 clang-tools-9 clang-9-doc libclang-common-9-dev libclang-9-dev libclang1-9 clang-format-9 libfuzzer-9-dev lldb-9 lld-9 libc++-9-dev libc++abi-9-dev \
 && sudo rm -rf /var/lib/apt/lists/*
