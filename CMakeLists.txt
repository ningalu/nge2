cmake_minimum_required(VERSION 3.20.2)
project(NGE2_Demo VERSION 1.0)
add_executable(${PROJECT_NAME} ./src/main.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(NGE_FRAMEWORK_DIR ${CMAKE_SOURCE_DIR}/src/Framework)
set(NGE_GAME_DIR ${CMAKE_SOURCE_DIR}/src/Game)
set(NGE_TESTS_DIR ${CMAKE_SOURCE_DIR}/src/Tests)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(./src/Framework/Core)
add_subdirectory(./src/Framework/Components)
add_subdirectory(./src/Game)
add_subdirectory(./src/Tests)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${CONAN_INCLUDE_DIRS}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

target_link_directories(
    ${PROJECT_NAME}
    PRIVATE ${CONAN_LIB_DIRS}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

if (MINGW)
    target_link_libraries(
        ${PROJECT_NAME}
        mingw32
        ${CONAN_LIBS}
        Core
        Game
    )
else()
    target_link_libraries(
        ${PROJECT_NAME}
        ${CONAN_LIBS}
        Core
        Game
    )
endif()

include(CTest)
add_executable(tests ./src/Tests/tests.cpp)
add_test(Tests tests)

target_include_directories(
    tests
    PUBLIC ${CONAN_INCLUDE_DIRS}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

target_link_directories(
    tests
    PRIVATE ${CONAN_LIB_DIRS}
    PUBLIC ${NGE_FRAMEWORK_DIR}
    PUBLIC ${NGE_GAME_DIR}
    PUBLIC ${NGE_TESTS_DIR}
)

target_link_libraries(
    tests
    ${CONAN_LIBS}
    Core
    Game
    Tests
)
