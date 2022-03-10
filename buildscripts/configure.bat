mkdir build
cd ./build
conan install .. --build=missing
cd ..
cmake -S . -B ./build