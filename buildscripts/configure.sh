#!/bin/sh
mkdir build
cd ./build
export CONAN_SYSREQUIRES_MODE=enabled
conan install .. --build=missing
cd ..
cmake -S . -B ./build