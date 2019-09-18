if [ ! -d "cmake-build" ]; then
  mkdir cmake-build
fi

pushd cmake-build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=/usr/bin/clang-9 -DCMAKE_CXX_COMPILER=/usr/bin/clang++-9 -G "CodeBlocks - Unix Makefiles" ../
popd