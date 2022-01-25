add_library(
    Core
    ./Game.cpp
    ./Timer.cpp
)

target_include_directories(
    Core
    PUBLIC A:/SDK/sdl2/SDL2-devel-2.0.14-mingw/SDL2-2.0.14/x86_64-w64-mingw32/include
)