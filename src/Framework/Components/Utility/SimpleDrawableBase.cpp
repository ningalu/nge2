#include "SimpleDrawableBase.h"

#include <iostream>
#include "Core/Utility/SDL_RectExtensions.h"

namespace nge {
    bool SimpleDrawableBase::Overlaps(SDL_Rect area) {
        return HasIntersect(dst_, area);
    }

    void SimpleDrawableBase::SetX(int x) {
        dst_.x = x;
    }

    void SimpleDrawableBase::SetY(int y) {
        dst_.y = y;
    }

    void SimpleDrawableBase::MoveX(int x) {
        dst_.x += x;
    }

    void SimpleDrawableBase::MoveY(int y) {
        dst_.y += y;
    }

    void SimpleDrawableBase::AlignHorizontal(int x) {
        dst_.x = x - (dst_.w / 2);
    }

    void SimpleDrawableBase::AlignVertical(int y) {
        dst_.y = y - (dst_.h / 2);
    }

    void SimpleDrawableBase::Rotate(double angle) {
        angle_ = angle;
    }

    void SimpleDrawableBase::SetAngle(double angle) {
        angle_ += angle;
    }

    SDL_Rect SimpleDrawableBase::GetDestRect() {
        return dst_;
    }

    int SimpleDrawableBase::GetX() {
        return dst_.x;
    }

    int SimpleDrawableBase::GetY() {
        return dst_.y;
    }

    int SimpleDrawableBase::GetW() {
        return dst_.w;
    }

    int SimpleDrawableBase::GetH() {
        return dst_.h;
    }

    int SimpleDrawableBase::GetCentreX() {
        return dst_.x + (dst_.w / 2);
    }

    int SimpleDrawableBase::GetCentreY() {
        return dst_.y + (dst_.h / 2);
    }

    double SimpleDrawableBase::GetAngle() {
        return angle_;
    }
    
    SimpleDrawableBase::~SimpleDrawableBase() {

    }
}