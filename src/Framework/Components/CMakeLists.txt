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
    PUBLIC ${CONAN_INCLUDE_DIRS}
)

target_link_directories(
    Components
    PRIVATE ${CONAN_LIB_DIRS}
)

if (MINGW)
    target_link_libraries(
        Components
        mingw32
        ${CONAN_LIBS}
        Core
    )
else()
    target_link_libraries(
        Components
        ${CONAN_LIBS}
        Core
    )
endif()