add_library(
    Game
    ./SampleState.cpp
    ./InitialState/InitialState.cpp
    ./OverworldState/Tileset.cpp
    ./OverworldState/Tilemap.cpp
)

target_include_directories(
    Game
    PUBLIC ${CMAKE_SOURCE_DIR}/src
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Framework
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Components
    PUBLIC ${SDL_INCLUDE_DIR}
    PUBLIC ${SDL_INCLUDE_DIR_SDL2}
    PUBLIC ${SDL_IMAGE_INCLUDE_DIR}
    PUBLIC ${SDL_MIXER_INCLUDE_DIR}
    PUBLIC ${SDL_TTF_INCLUDE_DIR}
)

target_link_directories(
    Game
    PRIVATE ${SDL_LIBRARY_DIR}
    PRIVATE ${SDL_IMAGE_LIBRARY_DIR}
    PRIVATE ${SDL_MIXER_LIBRARY_DIR}
    PRIVATE ${SDL_TTF_LIBRARY_DIR}
)

target_link_libraries(
    Game
    -lmingw32
    -lSDL2main
    -lSDL2
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_ttf
    Core
    Components
)