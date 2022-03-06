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
    PUBLIC ${CONAN_INCLUDE_DIRS}
)

target_link_directories(
    Core
    PRIVATE ${CONAN_LIB_DIRS}
)

if (MINGW)
    target_link_libraries(
        Core
        mingw32
        ${CONAN_LIBS}
    )
else()
    target_link_libraries(
        Core
        ${CONAN_LIBS}
    )
endif()