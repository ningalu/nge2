#include "SDL_RectExtensionsTests.h"

#include "SDL2/SDL.h"
#include "Core/Utility/SDL_RectExtensions.h"

TestResult HasIntersect_CornersOverlap();

TestResult RunSDL_RectExtensionTests() {
    return HasIntersect_CornersOverlap();
}

TestResult HasIntersect_CornersOverlap() {
    SDL_Rect r1{0, 0, 10, 10};
    SDL_Rect r2{9, 9, 10, 10};
    if (!HasIntersect(r1, r2)) {
        return TestResult::FAIL;
    }
    if (!HasIntersect(r2, r1)) {
        return TestResult::FAIL;
    }

    r1 = {9, 0, 10, 10};
    r2 = {0, 9, 10, 10};
    if (!HasIntersect(r1, r2)) {
        return TestResult::FAIL;
    }
    if (!HasIntersect(r2, r1)) {
        return TestResult::FAIL;
    }

    return TestResult::PASS;
}