cmake_minimum_required(VERSION 3.20.2)
project(NGE2_Demo VERSION 1.0)
add_executable(${PROJECT_NAME} ./src/main.cpp)

add_subdirectory(./src/Framework/Core)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ./src/Framework/Core
)

target_link_directories(
    ${PROJECT_NAME}
    PRIVATE ./src/Framework/Core
)

target_link_libraries(
    ${PROJECT_NAME}
    Core
)