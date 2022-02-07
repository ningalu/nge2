#include "SDL_RectExtensions.h"

bool operator==(SDL_Rect lhs, SDL_Rect rhs) {
    return (lhs.x == rhs.x)
    && (lhs.y == rhs.y)
    && (lhs.w == rhs.w)
    && (lhs.h == rhs.h);
}

std::ostream& operator<<(std::ostream& os, const SDL_Rect& rect) {
    os << "x: " 
    << rect.x 
    << "\ny: " 
    << rect.y 
    << "\nw: " 
    << rect.w 
    << "\nh: " 
    << rect.h;
    return os;
}