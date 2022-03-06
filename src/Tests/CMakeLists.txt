add_library(
    Tests
    ./SDL_RectExtensionsTests.cpp
)

target_include_directories(
    Tests
    PUBLIC ${CONAN_INCLUDE_DIRS}
    PUBLIC ${CMAKE_SOURCE_DIR}/src
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Framework
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Tests
)

target_link_directories(
    Tests
    PRIVATE ${CONAN_LIB_DIRS}
)

if (MINGW)
    target_link_libraries(
        Tests
        mingw32
        ${CONAN_LIBS}
        Core
        Components
    )
else()
    target_link_libraries(
        Tests
        ${CONAN_LIBS}
        Core
        Components
    )
endif()

