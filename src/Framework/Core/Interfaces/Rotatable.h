#ifndef _ROTATABLE_H
#define _ROTATABLE_H

class Rotatable {
    public:
        virtual void Rotate(double angle) = 0;
        virtual void SetAngle(double angle) = 0;
};

#endif