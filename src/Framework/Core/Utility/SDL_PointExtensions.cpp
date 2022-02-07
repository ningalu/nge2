#include "SDL_PointExtensions.h"

bool operator==(SDL_Point lhs, SDL_Point rhs) {
    return (lhs.x == rhs.x)
    && (lhs.y == rhs.y);
}