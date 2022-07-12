add_library(
    Components
    ./Sprite.cpp
    ./AnimatedSprite.cpp
    ./Button.cpp
    ./Text.cpp
    ./Switch.cpp
    ./Utility/SimpleDrawableBase.cpp
    ./Utility/AnimationState.cpp
)

target_include_directories(
    Components
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Framework
)

if (MINGW)
    target_link_libraries(
        Components
        mingw32
        SDL2::SDL2main
        sdl_image::sdl_image
        SDL2_ttf::SDL2_ttf
        nlohmann_json::nlohmann_json
        Core
    )
else()
    target_link_libraries(
        Components
        SDL2::SDL2main
        sdl_image::sdl_image
        SDL2_ttf::SDL2_ttf
        nlohmann_json::nlohmann_json
        Core
    )
endif()