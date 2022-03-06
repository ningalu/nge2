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
    # PUBLIC ${SDL_INCLUDE_DIR}
    # PUBLIC ${SDL_INCLUDE_DIR_SDL2}
    # PUBLIC ${SDL_IMAGE_INCLUDE_DIR}
    # PUBLIC ${SDL_MIXER_INCLUDE_DIR}
    # PUBLIC ${SDL_TTF_INCLUDE_DIR}
)

target_link_directories(
    Tests
    PRIVATE ${CONAN_LIB_DIRS}
    # PRIVATE ${SDL_LIBRARY_DIR}
    # PRIVATE ${SDL_IMAGE_LIBRARY_DIR}
    # PRIVATE ${SDL_MIXER_LIBRARY_DIR}
    # PRIVATE ${SDL_TTF_LIBRARY_DIR}
)

if (MINGW)
    target_link_libraries(
        Tests
        mingw32
        ${CONAN_LIBS}
        # SDL2main
        # SDL2
        # SDL2_image
        # SDL2_mixer
        # SDL2_ttf
        Core
        Components
    )
else()
    target_link_libraries(
        Tests
        ${CONAN_LIBS}
        # SDL2main
        # SDL2
        # SDL2_image
        # SDL2_mixer
        # SDL2_ttf
        Core
        Components
    )
endif()

