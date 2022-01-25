cmake_minimum_required(VERSION 3.20.2)
project(NGE2_Demo VERSION 1.0)
add_executable(${PROJECT_NAME} ./src/main.cpp)

set(SDL_LIBRARY_DIR "A:/SDK/sdl2/SDL2-devel-2.0.20-mingw/SDL2-2.0.20/x86_64-w64-mingw32/lib")
set(SDL_INCLUDE_DIR "A:/SDK/sdl2/SDL2-devel-2.0.20-mingw/SDL2-2.0.20/x86_64-w64-mingw32/include")

message(STATUS ${SDL_LIBRARY_DIR})
message(STATUS ${SDL_INCLUDE_DIR})

add_subdirectory(./src/Framework/Core)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${SDL_INCLUDE_DIR}
    PUBLIC ./src/Framework/Core
)

target_link_directories(
    ${PROJECT_NAME}
    PRIVATE ${SDL_LIBRARY_DIR}
    PRIVATE ./src/Framework/Core
)

target_link_libraries(
    ${PROJECT_NAME}
    -lmingw32
    -lSDL2main
    -lSDL2
    Core
    
)