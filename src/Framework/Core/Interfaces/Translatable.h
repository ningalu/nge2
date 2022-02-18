#ifndef _TRANSLATABLE_H
#define _TRANSLATABLE_H

class Translatable {
    public:
        virtual int GetX() = 0;
        virtual int GetY() = 0;
        virtual void SetX(int x) = 0;
        virtual void SetY(int y) = 0;
        virtual void MoveX(int x) = 0;
        virtual void MoveY(int y) = 0;
};
#endif