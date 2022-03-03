#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include "SDL2/SDL.h"

class Drawable {
    public:
        virtual void Draw() = 0;
        virtual bool Overlaps(SDL_Rect area) = 0;
};

template <typename T>
int GetCentreX(T& drawable) {
    return (drawable.GetX() + (drawable.GetW() / 2));
}

template <typename T>
int GetCentreY(T& drawable) {
    return (drawable.GetY() + (drawable.GetH() / 2));
}

#endif