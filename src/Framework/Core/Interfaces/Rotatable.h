#ifndef _FRAMEWORK_CORE_INPUTINTERFACES_ROTATABLE_H
#define _FRAMEWORK_CORE_INPUTINTERFACES_ROTATABLE_H

class Rotatable {
    public:
        virtual void Rotate(double angle) = 0;
        virtual void SetAngle(double angle) = 0;
};

#endif