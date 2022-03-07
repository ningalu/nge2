#include "SDL_PointExtensions.h"

bool operator==(SDL_Point lhs, SDL_Point rhs) {
    return (lhs.x == rhs.x)
    && (lhs.y == rhs.y);
}

std::ostream& operator<<(std::ostream& os, const SDL_Point& point) {
    os << "x: "
    << point.x
    << "\ny: "
    << point.y;
    return os;
}