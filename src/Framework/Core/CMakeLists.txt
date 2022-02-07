add_library(
    Core
    ./Game.cpp
    ./Timer.cpp
    ./Graphics.cpp
    ./Input.cpp
    ./State.cpp
    ./StateManager.cpp
    ./Audio.cpp
    ./Utility/SDL_RectExtensions.cpp
    ./Utility/SDL_PointExtensions.cpp
)

target_include_directories(
    Core
    PUBLIC ${SDL_INCLUDE_DIR}
    PUBLIC ${SDL_INCLUDE_DIR}/SDL2
    PUBLIC ${SDL_IMAGE_INCLUDE_DIR}
    PUBLIC ${SDL_MIXER_INCLUDE_DIR}
    PUBLIC ${SDL_TTF_INCLUDE_DIR}
)

target_link_directories(
    Core
    PRIVATE ${SDL_LIBRARY_DIR}
    PRIVATE ${SDL_IMAGE_LIBRARY_DIR}
    PRIVATE ${SDL_MIXER_LIBRARY_DIR}
    PRIVATE ${SDL_TTF_LIBRARY_DIR}
)

target_link_libraries(
    Core
    -lmingw32
    -lSDL2main
    -lSDL2
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_ttf
)