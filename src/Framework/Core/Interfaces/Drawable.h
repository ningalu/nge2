#ifndef _DRAWABLE_H
#define _DRAWABLE_H

class Drawable {
    public:
        virtual void Draw() = 0;
        virtual int GetX() = 0;
        virtual int GetY() = 0;
        virtual int GetW() = 0;
        virtual int GetH() = 0;

};

#endif