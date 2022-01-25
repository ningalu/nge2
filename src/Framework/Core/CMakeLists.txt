add_library(
    Core
    ./Game.cpp
    ./Timer.cpp
)

target_include_directories(
    Core
    PUBLIC ${SDL_INCLUDE_DIR}
)

target_link_directories(
    Core
    PRIVATE ${SDL_LIBRARY_DIR}
)

target_link_libraries(
    Core
    -lmingw32
    -lSDL2main
    -lSDL2
)