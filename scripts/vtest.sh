#!/usr/bin/env bash

BASEDIR=$(dirname "$0")

if [ ! -f 'build/meson-out/brill' ]; then
    .$(BASEDIR)/build.sh
fi

if [ -f 'build/meson-out/brill' ]; then
    pushd build
    meson test --wrap=valgrind
    popd
fi