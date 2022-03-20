#include "SDL_PointExtensions.h"

bool operator==(SDL_Point lhs, SDL_Point rhs) {
    return (lhs.x == rhs.x)
    && (lhs.y == rhs.y);
}

bool operator!=(SDL_Point lhs, SDL_Point rhs) {
    return (lhs.x != rhs.x)
    || (lhs.y != rhs.y);
}

std::ostream& operator<<(std::ostream& os, const SDL_Point& point) {
    os << "x: "
    << point.x
    << "\ny: "
    << point.y;
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<SDL_Point>& points) {
    for (auto point : points) {
        os << point << "\n";
    }
    return os;
}