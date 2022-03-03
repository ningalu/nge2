#ifndef _FRAMEWORK_CORE_UTILITY_SDL_EVENTEXTENSIONS_H
#define _FRAMEWORK_CORE_UTILITY_SDL_EVENTEXTENSIONS_H

#include <ostream>
#include "SDL2/SDL.h"

std::ostream& operator<<(std::ostream& os, const SDL_Event& event);

#endif