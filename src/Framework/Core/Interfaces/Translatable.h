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

template <typename T1, typename T2>
void AlignHorizontal(T1& origin, T2& toMove) {
    toMove.SetX(GetCentreX(origin) - (toMove.GetW() / 2));
}

template <typename T1, typename T2>
void AlignVertical(T1& origin, T2& toMove) {
    toMove.SetY(GetCentreY(origin) - (toMove.GetH() / 2));
}

#endif