if [ ! -d "cmake-build-debug" ]; then
  mkdir cmake-build-debug
fi

pushd cmake-build-debug
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=On -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ../
#cmake -DCMAKE_VERBOSE_MAKEFILE=On -DCMAKE_EXPORT_COMPILE_COMMANDS=On -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ../
popd