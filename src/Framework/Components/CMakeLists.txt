add_library(
    Components
    ./Sprite.cpp
    ./AnimatedSprite.cpp
    ./Button.cpp
    ./Text.cpp
    ./Utility/SimpleDrawableBase.cpp
)

target_include_directories(
    Components
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Framework/Core
    PUBLIC ${SDL_INCLUDE_DIR}
    PUBLIC ${SDL_INCLUDE_DIR_SDL2}
    PUBLIC ${SDL_IMAGE_INCLUDE_DIR}
    PUBLIC ${SDL_MIXER_INCLUDE_DIR}
    PUBLIC ${SDL_TTF_INCLUDE_DIR}
)

target_link_directories(
    Components
    PRIVATE ${SDL_LIBRARY_DIR}
    PRIVATE ${SDL_IMAGE_LIBRARY_DIR}
    PRIVATE ${SDL_MIXER_LIBRARY_DIR}
    PRIVATE ${SDL_TTF_LIBRARY_DIR}
)

target_link_libraries(
    Components
    -lmingw32
    -lSDL2main
    -lSDL2
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_ttf
    Core
)