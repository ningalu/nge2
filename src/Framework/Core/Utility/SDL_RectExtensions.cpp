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

bool PointInRect(const SDL_Point& p, const SDL_Rect& r) {
    return (r.x <= p.x)
    && ((r.x + r.w) >= p.x)
    && (r.y <= p.y)
    && ((r.y + r.h) >= p.y);
}