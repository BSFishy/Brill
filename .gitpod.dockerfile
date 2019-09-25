FROM gitpod/workspace-full

USER root

# Add llvm stuff
RUN curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
  && apt-add-repository -yu "deb http://apt.llvm.org/disco/ llvm-toolchain-disco main" \
  && apt-add-repository -yu "deb http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main" \
  && sudo sh -c "echo deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco main \ >> /etc/apt/sources.list" \
  && sudo sh -c "echo deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main \ >> /etc/apt/sources.list" \
  && sudo apt-get update

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
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
  && ln -s /usr/bin/clang++-10 /usr/bin/clang++ \
  && ln -s /usr/bin/clang-10 /usr/bin/clang

# CLang 9
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    clang-9 \
    clang-tools-9 \
    clang-9-doc \
    libclang-common-9-dev \
    libclang-9-dev \
    libclang1-9 \
    clang-format-9 \
    clangd-9 \
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

# LibC++ 10
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    libc++-10-dev \
    libc++abi-10-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LibC++ 9
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    libc++-9-dev \
    libc++abi-9-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# OpenMP
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    libomp-10-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Antlr
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    antlr4 \
    libantlr4-runtime-dev \
    libantlr4-runtime4.7.2 \
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
RUN git clone https://github.com/antlr/antlr4.git && cd antlr4 \
  && git reset --hard 06705edafd6b77d455f403c6297e25f9e718406b \
  && cd runtime/Cpp \
  && mkdir build && mkdir run && cd build \
  && cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=/usr/bin/clang++-9 -DCMAKE_C_COMPILER=/usr/bin/clang-9 -DWITH_DEMO=False -DANTLR4_INSTALL=True \
  && make \
  && sudo make install
