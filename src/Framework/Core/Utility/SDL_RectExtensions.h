#ifndef _SDL_RECTEXTENSIONS_H
#define _SDL_RECTEXTENSIONS_H

#include "SDL2/SDL.h"
#include <iostream>

bool operator==(SDL_Rect lhs, SDL_Rect rhs);
std::ostream& operator<<(std::ostream& os, const SDL_Rect& rect);

#endif