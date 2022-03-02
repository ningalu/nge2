#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include "SDL2/SDL.h"

class Drawable {
    public:
        virtual void Draw() = 0;
        virtual int GetX() = 0;
        virtual int GetY() = 0;
        virtual int GetW() = 0;
        virtual int GetH() = 0;
        virtual SDL_Rect GetDestRect() = 0;
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