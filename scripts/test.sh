#!/usr/bin/env bash

BASEDIR=$(dirname "$0")

if [ ! -f 'build/src/brill' ]; then
    .$(BASEDIR)/build.sh
fi

if [ -f 'build/src/brill' ]; then
    pushd build
    meson test
    popd
fi