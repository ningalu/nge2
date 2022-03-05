add_library(
    Components
    ./Sprite.cpp
    ./AnimatedSprite.cpp
    ./Button.cpp
    ./Text.cpp
    ./Utility/SimpleDrawableBase.cpp
    ./Utility/AnimationState.cpp
)

target_include_directories(
    Components
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Framework
    PUBLIC ${CONAN_INCLUDE_DIRS}
    #PUBLIC ${SDL_INCLUDE_DIR}
    #PUBLIC ${SDL_INCLUDE_DIR_SDL2}
    #PUBLIC ${SDL_IMAGE_INCLUDE_DIR}
    #PUBLIC ${SDL_MIXER_INCLUDE_DIR}
    #PUBLIC ${SDL_TTF_INCLUDE_DIR}
)

target_link_directories(
    Components
    PRIVATE ${CONAN_LIB_DIRS}
    #PRIVATE ${SDL_LIBRARY_DIR}
    #PRIVATE ${SDL_IMAGE_LIBRARY_DIR}
    #PRIVATE ${SDL_MIXER_LIBRARY_DIR}
    #PRIVATE ${SDL_TTF_LIBRARY_DIR}
)

target_link_libraries(
    Components
    ${CONAN_LIBS}
    #SDL2main
    #SDL2
    #SDL2_image
    #SDL2_mixer
    #SDL2_ttf
    Core
)