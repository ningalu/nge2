#ifndef _FRAMEWORK_CORE_UTILITY_SDL_POINTEXTENSIONS_H
#define _FRAMEWORK_CORE_UTILITY_SDL_POINTEXTENSIONS_H

#include <ostream>

#include "SDL2/SDL.h"

bool operator==(SDL_Point lhs, SDL_Point rhs);
std::ostream& operator<<(std::ostream& os, const SDL_Point& point);

#endif