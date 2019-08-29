FROM gitpod/workspace-full

USER root

RUN sudo apt-get update \
 && sudo apt-get install -yq \
    ninja-build \
    llvm-defaults \
 && sudo rm -rf /var/lib/apt/lists/*
