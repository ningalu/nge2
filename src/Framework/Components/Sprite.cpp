#include "Sprite.h"

#include <climits>

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
    ) : graphics_(graphics), src_(src), dst_(dst), angle_(angle), rotation_centre_(rotationCentre), flip_(flip) {
        texture_ = graphics_->LoadTexture(texturePath);
    }

    void Sprite::Draw() {
        graphics_->DrawTexture(
            texture_.get(), 
            src_ == FULL_TEXTURE ? nullptr : &src_, 
            &dst_, 
            angle_, 
            rotation_centre_ == ROTATION_CENTRE ? nullptr : &rotation_centre_, 
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