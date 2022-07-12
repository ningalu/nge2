#include "gtest/gtest.h"
#include "SDL2/SDL.h"
#include "Core/Utility/SDL_RectExtensions.h"

TEST(SDLRectExtensions, IntersectingCorners) {
    SDL_Rect r1{0, 0, 10, 10};
    SDL_Rect r2{9, 9, 10, 10};
    EXPECT_TRUE(HasIntersect(r1, r2));
    EXPECT_TRUE(HasIntersect(r2, r1));
}

TEST(SDLRectExtentions, NonIntersectingCorners) {
    SDL_Rect r1 = {0, 0, 5, 5};
    SDL_Rect r2 = {6, 6, 11, 11};
    EXPECT_FALSE(HasIntersect(r1, r2));
    EXPECT_FALSE(HasIntersect(r2, r1));
}