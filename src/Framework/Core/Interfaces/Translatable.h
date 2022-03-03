#ifndef _TRANSLATABLE_H
#define _TRANSLATABLE_H

#include "Drawable.h"

class Translatable {
    public:
        virtual void SetX(int x) = 0;
        virtual void SetY(int y) = 0;
        virtual void MoveX(int x) = 0;
        virtual void MoveY(int y) = 0;
        virtual void AlignHorizontal(int x) = 0;
        virtual void AlignVertical(int y) = 0;
};

#endif