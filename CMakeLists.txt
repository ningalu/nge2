cmake_minimum_required(VERSION 3.20.2)
project(NGE2_Demo VERSION 1.0)
add_executable(${PROJECT_NAME} ./src/main.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SDL_LIBRARY_DIR "A:/SDK/sdl2/SDL2-devel-2.0.20-mingw/SDL2-2.0.20/x86_64-w64-mingw32/lib")
set(SDL_INCLUDE_DIR "A:/SDK/sdl2/SDL2-devel-2.0.20-mingw/SDL2-2.0.20/x86_64-w64-mingw32/include")
set(SDL_IMAGE_LIBRARY_DIR "A:/SDK/sdl2_image/SDL2_image-devel-2.0.5-mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/lib")
set(SDL_IMAGE_INCLUDE_DIR "A:/SDK/sdl2_image/SDL2_image-devel-2.0.5-mingw/SDL2_image-2.0.5/x86_64-w64-mingw32/include")
set(SDL_MIXER_LIBRARY_DIR "A:/SDK/sdl2_mixer/SDL2_mixer-devel-2.0.4-mingw/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib")
set(SDL_MIXER_INCLUDE_DIR "A:/SDK/sdl2_mixer/SDL2_mixer-devel-2.0.4-mingw/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include")
set(SDL_TTF_LIBRARY_DIR "A:/SDK/sdl2_ttf/SDL2_ttf-devel-2.0.15-mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib")
set(SDL_TTF_INCLUDE_DIR "A:/SDK/sdl2_ttf/SDL2_ttf-devel-2.0.15-mingw/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include")
set(NGE_FRAMEWORK_DIR ${CMAKE_SOURCE_DIR}/src/Framework)
set(NGE_GAME_DIR ${CMAKE_SOURCE_DIR}/src/Game)
set(NGE_TESTS_DIR ${CMAKE_SOURCE_DIR}/src/Tests)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(./src/Framework/Core)
add_subdirectory(./src/Framework/Components)
add_subdirectory(./src/Game)
add_subdirectory(./src/Tests)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${SDL_INCLUDE_DIR}
    PUBLIC ${SDL_INCLUDE_DIR}/SDL2
    PUBLIC ${SDL_IMAGE_INCLUDE_DIR}
    PUBLIC ${SDL_MIXER_INCLUDE_DIR}
    PUBLIC ${SDL_TTF_INCLUDE_DIR}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

target_link_directories(
    ${PROJECT_NAME}
    PRIVATE ${SDL_LIBRARY_DIR}
    PRIVATE ${SDL_IMAGE_LIBRARY_DIR}
    PRIVATE ${SDL_MIXER_LIBRARY_DIR}
    PRIVATE ${SDL_TTF_LIBRARY_DIR}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    -lmingw32
    -lSDL2main
    -lSDL2
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_ttf
    Core
    Game
)

include(CTest)
add_executable(tests ./src/tests/tests.cpp)
add_test(Tests tests)

target_include_directories(
    tests
    PUBLIC ${SDL_INCLUDE_DIR}
    PUBLIC ${SDL_INCLUDE_DIR}/SDL2
    PUBLIC ${SDL_IMAGE_INCLUDE_DIR}
    PUBLIC ${SDL_MIXER_INCLUDE_DIR}
    PUBLIC ${SDL_TTF_INCLUDE_DIR}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

target_link_directories(
    tests
    PRIVATE ${SDL_LIBRARY_DIR}
    PRIVATE ${SDL_IMAGE_LIBRARY_DIR}
    PRIVATE ${SDL_MIXER_LIBRARY_DIR}
    PRIVATE ${SDL_TTF_LIBRARY_DIR}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

target_link_libraries(
    tests
    -lmingw32
    -lSDL2main
    -lSDL2
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_ttf
    Core
    Game
    Tests
)
