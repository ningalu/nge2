add_library(
    Game
    ./SampleState.cpp
    ./InitialState/InitialState.cpp
    ./OverworldState/Tileset.cpp
    ./OverworldState/Tilemap.cpp
    ./OverworldState/OverworldState.cpp
)

target_include_directories(
    Game
    PUBLIC ${CONAN_INCLUDE_DIRS}
    PUBLIC ${CMAKE_SOURCE_DIR}/src
    PUBLIC ${CMAKE_SOURCE_DIR}/src/Framework
)

target_link_directories(
    Game
    PRIVATE ${CONAN_LIB_DIRS}
)

if (MINGW)
    target_link_libraries(
        Game
        mingw32
        ${CONAN_LIBS}
        Core
        Components
    )
else()
    target_link_libraries(
        Game
        ${CONAN_LIBS}
        Core
        Components
    )
endif()