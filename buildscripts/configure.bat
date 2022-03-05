mkdir build
cd ./build
conan install .. --profile=MSVC
cd ..
cmake -S . -B ./build