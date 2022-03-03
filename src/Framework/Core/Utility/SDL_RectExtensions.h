#ifndef _FRAMEWORK_CORE_UTILITY_SDL_RECTEXTENSIONS_H
#define _FRAMEWORK_CORE_UTILITY_SDL_RECTEXTENSIONS_H

#include "SDL2/SDL.h"
#include <iostream>

bool operator==(SDL_Rect lhs, SDL_Rect rhs);
std::ostream& operator<<(std::ostream& os, const SDL_Rect& rect);
// Copying simple values vs passing const reference?
bool PointInRect(SDL_Point p, SDL_Rect r);
bool HasIntersect(SDL_Rect r1, SDL_Rect r2);

#endif