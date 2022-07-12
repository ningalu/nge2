# NGE2

[![CMake](https://github.com/ningalu/nge2/actions/workflows/cmake.yml/badge.svg)](https://github.com/ningalu/nge2/actions/workflows/cmake.yml)  
NGE2 is my second attempt at a larger scale C++ project that tries to consider non-code elements like build systems, portability, distribution, etc. as well as slightly higher level design decisions like usability as a library, compilation/linking order, and module dependencies within the project. It is built with CMake and wraps the SDL2 libraries. It is designed to give structure and utilities to GUI projects and games I might want to make.

# Build

Currently tested and working on Windows 10 with MSVC 19 and Ubuntu 20.04 with GCC 9.4

### Installations

- Install a C++ compiler (Windows must use Microsoft Visual C++)
- Install Python 3
- Install CMake 3.20.2 or greater
- Install Conan

### Building

- Clone and navigate into the repo
- Install the Conan dependencies and configure the CMake project manually or use the build script  
  `python build.py all`
