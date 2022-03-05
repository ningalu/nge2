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
    ./Utility/SDL_EventExtensions.cpp
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
    SDL2main
    SDL2
    SDL2_image
    SDL2_mixer
    SDL2_ttf
)