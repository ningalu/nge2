mkdir build
cd ./build
conan install ..
cd ..
cmake -S . -B ./build -G "MinGW Makefiles"