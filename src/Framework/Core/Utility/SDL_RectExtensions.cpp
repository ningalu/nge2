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

bool PointInRect(SDL_Point p, SDL_Rect r) {
    return (r.x <= p.x)
    && ((r.x + r.w) >= p.x)
    && (r.y <= p.y)
    && ((r.y + r.h) >= p.y);
}

bool HasIntersect(SDL_Rect r1, SDL_Rect r2) {
    return (r1.x < (r2.x + r2.w))
    && ((r1.x + r1.w) > r2.x)
    && (r1.y < (r2.y + r2.h))
    && ((r1.y + r1.h) > r2.y);
}