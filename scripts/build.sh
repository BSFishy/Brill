if [ ! -f 'build/build.ninja' ]; then
    # CC=clang-10 CXX=clang++-10 meson build
    meson build
fi

if [ -f 'build/build.ninja' ]; then
    pushd build
    ninja
    popd
fi
