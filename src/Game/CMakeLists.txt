add_library(
    Game
    ./SampleState.cpp
    ./InitialState/InitialState.cpp
    ./OverworldState/Tileset.cpp
    ./OverworldState/Tilemap.cpp
    ./OverworldState/OverworldState.cpp
    ./MiningState/MiningState.cpp
)

target_include_directories(
    Game
    PUBLIC ${CMAKE_SOURCE_DIR}/src
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Framework
)

if (MINGW)
    target_link_libraries(
        Game
        mingw32
        Core
        Components
    )
else()
    target_link_libraries(
        Game
        Core
        Components
    )
endif()