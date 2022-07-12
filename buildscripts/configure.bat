mkdir build
cd ./build
conan install .. --build=missing -pr:b=default
cd ..
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake"