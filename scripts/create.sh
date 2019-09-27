if [ ! -d "cmake-build-debug" ]; then
  mkdir cmake-build-debug
fi

pushd cmake-build-debug
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=/usr/bin/clang-10 -DCMAKE_CXX_COMPILER=/usr/bin/clang++-10 -G "CodeBlocks - Unix Makefiles" ../
popd