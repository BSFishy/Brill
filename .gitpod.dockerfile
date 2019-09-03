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
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

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
RUN sudo apt-get update \
  && sudo apt-get install -yq \
    ninja-build \
  && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

# Antlr
RUN sudo curl https://www.antlr.org/download/antlr-4.7.2-complete.jar -o /usr/local/lib/antlr.jar \
  && echo "#!/bin/sh\n\njava -jar /usr/local/lib/antlr.jar $@" >> /usr/bin/antlr \
  && sudo chmod 777 /usr/bin/antlr

USER gitpod

RUN export CLASSPATH=".:/usr/local/lib/antlr.jar:$CLASSPATH"
