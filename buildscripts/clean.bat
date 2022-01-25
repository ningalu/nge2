echo Cleaning
cd build
rmdir /S /Q CMakeFiles
rmdir /S /Q src
del cmake_install.cmake
del CMakeCache.txt
del Makefile
