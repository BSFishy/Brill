FROM gitpod/workspace-full

USER root

# Add llvm stuff
RUN curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
    && apt-add-repository -yu "deb http://apt.llvm.org/disco/ llvm-toolchain-disco main" \
    && apt-add-repository -yu "deb http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main" \
    && sudo sh -c "echo deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco main \ >> /etc/apt/sources.list" \
    && sudo sh -c "echo deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main \ >> /etc/apt/sources.list" \
    && sudo apt-get update

# GCC
RUN sudo apt-get update && sudo apt-get install -yq build-essential software-properties-common \
#    && apt-add-repository -yu ppa:ubuntu-toolchain-r/test && sudo apt-get update \
    && sudo apt-get install -yq gcc-9 g++-9 \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# GCC Alternatives
RUN sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9
#    && sudo update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 90

# LLVM
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    libllvm10 \
    llvm-10 \
    llvm-10-dev \
    llvm-10-doc \
    llvm-10-examples \
    llvm-10-runtime \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# CLang 10
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    clang-10 \
    clang-tools-10 \
    clang-10-doc \
    libclang-common-10-dev \
    libclang-10-dev \
    libclang1-10 \
    clang-format-10 \
    clangd-10 \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# CLang Alternatives
# RUN sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-10 100 --slave /usr/bin/clang++ clang++ /usr/bin/clang++-10 \
#     && sudo update-alternatives --install /usr/bin/cc cc /usr/bin/clang-10 100 \
#     && sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-10 100

# LibC++ 10
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    libc++-10-dev \
    libc++abi-10-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LibFuzzer
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    libfuzzer-10-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LLDB
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    lldb-10 \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LLD
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    lld-10 \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LLD Alternatives
RUN sudo update-alternatives --install /usr/bin/lld lld /usr/bin/lld-10 100 \
    && sudo update-alternatives --install /usr/bin/ld ld /usr/bin/ld.lld-10 100

# OpenMP
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    libomp-10-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Valgrind
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    valgrind \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Antlr
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    antlr4 \
    pkg-config \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*
RUN cd /usr/local/lib \
    && sudo curl -O https://www.antlr.org/download/antlr-4.7.2-complete.jar

# Git
RUN sudo apt-get update \
    && sudo apt-get install -yq \
    git \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Install antlr stuff
RUN git clone https://github.com/BSFishy/antlr4.git && cd antlr4 \
    && cd runtime/Cpp \
    && mkdir build && mkdir run && cd build \
    && cmake .. -DWITH_DEMO=False -DCMAKE_BUILD_TYPE=Release -DANTLR4_INSTALL=True -DWITH_LIBCXX=False -G "CodeBlocks - Unix Makefiles" \
    && make -j 16 \
    && sudo make install \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*
