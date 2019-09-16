FROM gitpod/workspace-full

USER root

# Add llvm stuff
RUN curl -fsSL https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - \
  && apt-add-repository -yu "deb http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main" \
  && sudo sh -c "echo deb-src http://apt.llvm.org/disco/ llvm-toolchain-disco-9 main \ >> /etc/apt/sources.list" \
  && sudo apt-get update

# LLVM
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    libllvm-9-ocaml-dev \
    libllvm9 \
    llvm-9 \
    llvm-9-dev \
    llvm-9-doc \
    llvm-9-examples \
    llvm-9-runtime \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# CLang
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    clang-9 \
    #clang-tools-9 \
    clang-9-doc \
    libclang-common-9-dev \
    libclang-9-dev \
    libclang1-9 \
    clang-format-9 \
    python-clang-9 \
    clangd-9 \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* \
  && ln -s /usr/bin/clang++-9 /usr/bin/clang++ \
  && ln -s /usr/bin/clang-9 /usr/bin/clang

# LibFuzzer
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    libfuzzer-9-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LLDB
# RUN sudo apt-get update \
#   && sudo apt-get install -yq \
#     llvm-9-dev \
#     lldb-9 \
#   && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LLD
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    lld-9 \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# LibC++
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    libc++-9-dev \
    libc++abi-9-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Ninja
# RUN sudo apt-get update \
#   && sudo apt-get install -yq \
#     ninja-build \
#   && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Antlr
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    antlr4 \
    libantlr4-runtime-dev \
    libantlr4-runtime4.7.2 \
    pkg-config \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Git
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    git \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Install antlr stuff
RUN git clone --branch 4.7 https://github.com/antlr/antlr4.git \
  && cd antlr4/runtime/Cpp \
  && mkdir build && mkdir run && cd build \
  && cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/clang++-9 -DCMAKE_C_COMPILER=/usr/bin/clang-9 -DANTLR_JAR_LOCATION=/usr/share/java/antlr4-4.7.2.jar -DWITH_DEMO=True -DANTLR4_INSTALL=True \
  && make \
  && sudo make install

# USER gitpod

# ENV CLASSPATH=.:/usr/local/lib/antlr.jar:$CLASSPATH
