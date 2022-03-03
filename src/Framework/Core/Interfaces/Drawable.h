#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include "SDL2/SDL.h"

class Drawable {
    public:
        virtual void Draw() = 0;
        virtual bool Overlaps(SDL_Rect area) = 0;
};

#endif