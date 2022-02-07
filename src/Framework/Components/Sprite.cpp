#include "Sprite.h"

#include <climits>
#include <iostream>

#include "Utility/SDL_RectExtensions.h"
#include "Utility/SDL_PointExtensions.h"

namespace nge {

    const SDL_Rect Sprite::FULL_TEXTURE = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    const SDL_Point Sprite::ROTATION_CENTRE = {INT_MIN, INT_MIN};

    Sprite::Sprite(
        std::shared_ptr<Graphics> graphics, 
        std::string texturePath, 
        SDL_Rect src, 
        SDL_Rect dst,
        double angle,
        SDL_Point rotationCentre,
        SDL_RendererFlip flip
    ) : graphics_(graphics), dst_(dst), angle_(angle), flip_(flip) {
        texture_ = graphics_->LoadTexture(texturePath);
        if (src == FULL_TEXTURE) {
            src_.x = 0;
            src_.y = 0;
            SDL_QueryTexture(texture_.get(), nullptr, nullptr, &src_.w, &src_.h);
        } else {
            src_ = src;
        }
        if (rotationCentre == ROTATION_CENTRE) {
            rotation_centre_.x = dst_.w / 2;
            rotation_centre_.y = dst_.h / 2;
        } else {
            rotation_centre_ = rotationCentre;
        }
        
    }

    void Sprite::Draw() {
        graphics_->DrawTexture(
            texture_.get(), 
            &src_, 
            &dst_, 
            angle_, 
            &rotation_centre_,
            flip_
        );
    }

    int Sprite::GetX() {
        return dst_.x;
    }

    int Sprite::GetY() {
        return dst_.y;
    }

    void Sprite::SetX(int x) {
        dst_.x = x;
    }

    void Sprite::SetY(int y) {
        dst_.y = y;
    }

    void Sprite::MoveX(int x) {
        dst_.x += x;
    }

    void Sprite::MoveY(int y) {
        dst_.y += y;
    }

    double Sprite::GetAngle() {
        return angle_;
    }
    void Sprite::Rotate(double angle) {
        angle_ += angle;
    }
    void Sprite::SetAngle(double angle) {
        angle_ = angle;
    }

    Sprite::~Sprite() {

    }
}