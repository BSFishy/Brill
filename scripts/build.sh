if [ ! -f 'build/build.ninja' ]; then
    meson build
fi

if [ -f 'build/build.ninja' ]; then
    pushd build
    ninja
    popd
fi
