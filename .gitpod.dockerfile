FROM gitpod/workspace-full

USER root

RUN sudo apt-get update \
 && sudo apt-get install -yq \
    ninja-build \
    clang-8 \
 && sudo rm -rf /var/lib/apt/lists/*