cmake_minimum_required(VERSION 3.20.2)
project(NGE2_Demo VERSION 1.0)

find_package(SDL2)
find_package(sdl_image)
find_package(SDL2_ttf)
find_package(nlohmann_json)
find_package(GTest)

add_executable(${PROJECT_NAME} ./src/main.cpp)

set(NGE_FRAMEWORK_DIR ${CMAKE_SOURCE_DIR}/src/Framework)
set(NGE_GAME_DIR ${CMAKE_SOURCE_DIR}/src/Game)
set(NGE_TESTS_DIR ${CMAKE_SOURCE_DIR}/src/Tests)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)

add_subdirectory(./src/Framework/Core)
add_subdirectory(./src/Framework/Components)
add_subdirectory(./src/Game)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${NGE_GAME_DIR}
)
if (MINGW)
    target_link_libraries(
        ${PROJECT_NAME}
        mingw32
        SDL2::SDL2main
        sdl_image::sdl_image
        SDL2_ttf::SDL2_ttf
        nlohmann_json::nlohmann_json
        Core
        Game
    )
else()
    target_link_libraries(
        ${PROJECT_NAME}
        SDL2::SDL2main
        sdl_image::sdl_image
        SDL2_ttf::SDL2_ttf
        nlohmann_json::nlohmann_json
        Core
        Game
    )
endif()

enable_testing()
add_executable(
    unit_tests 
    ./src/Tests/SDL_RectExtensionsTests.cpp
)
target_include_directories(
    unit_tests
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)
target_link_libraries(
    unit_tests
    gtest::gtest
    SDL2::SDL2main
    sdl_image::sdl_image
    SDL2_ttf::SDL2_ttf
    Core
)