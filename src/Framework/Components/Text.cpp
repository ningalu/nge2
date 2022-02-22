#include "Text.h"

namespace nge {

    Text::Text(
        std::shared_ptr<Graphics> graphics, 
        FontPtr font, 
        FontStyle style,
        const std::string& text, 
        SDL_Point dst, 
        SDL_Color colour,
        SDL_Color bg,
        double angle,
        SDL_Point rotationCentre,
        SDL_RendererFlip flip
    ) : graphics_(graphics) {
        texture_ = graphics_->LoadText(font, style, text, colour, bg);
    }

    void Text::Draw() {
        graphics_->DrawTexture(texture_, &src_, &dst_, angle_, &rotation_centre_, flip_);
    }

    int Text::GetX() {
        return dst_.x;
    }

    int Text::GetY() {
        return dst_.y;
    }

    void Text::SetX(int x) {
        dst_.x = x;
    }

    void Text::SetY(int y) {
        dst_.y = y;
    }

    void Text::MoveX(int x) {
        dst_.x += x;
    }

    void Text::MoveY(int y) {
        dst_.y += y;
    }

    double Text::GetAngle() {
        return angle_;
    }
    void Text::Rotate(double angle) {
        angle_ += angle;
    }
    void Text::SetAngle(double angle) {
        angle_ = angle;
    }
}