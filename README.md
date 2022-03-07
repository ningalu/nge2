# NGE2

NGE2 is my second attempt at a larger scale C++ project that tries to consider non-code elements like build systems, portability, distribution, etc. as well as slightly higher level design decisions like usability as a library, compilation/linking order, and module dependencies within the project. It is built with CMake and wraps the SDL2 libraries. It is designed to give structure and utilities to GUI projects and games I might want to make.

# Build
## Windows
### Installations
- Install Microsoft Visual C++
- Install Python 3
- Install CMake 3.20.2 or greater
- Install Conan
### Building
- Clone and navigate into the repo
- Configure the CMake project manually or using the build script  
```python build.py all```