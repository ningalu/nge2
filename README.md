# NGE2

NGE2 is my second attempt at a larger scale C++ project that tries to consider non-code elements like build systems, portability, distribution, etc. as well as slightly higher level design decisions like usability as a library, compilation/linking order, and module dependencies within the project. It is built with CMake and wraps the SDL2 libraries. It is designed to give structure and utilities to GUI projects and games I might want to make. 

## TODO notes:
reexamine usage of shared pointer and object ownerships
concept of automatic z levels for drawables instead of forced user defined draw orders per state (sort on every insertion to drawing list?)
const correctness, pass by reference, inline where applicable
fix namespacing and include guards
button construction is convoluted
improve templating of initial state creation
move input processing into states?
input handling needs a longer history of mouse and keyboard states to allow buffers of precision, like allowing a 5 frame buffer before an input is considered "held"