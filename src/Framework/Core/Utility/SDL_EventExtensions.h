#ifndef SDL_EVENTEXTENSIONS_H
#define SDL_EVENTEXTENSIONS_H

#include <ostream>
#include "SDL2/SDL.h"

std::ostream& operator<<(std::ostream& os, const SDL_Event& event);

#endif