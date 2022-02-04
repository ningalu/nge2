#include "Sprite.h"

#include <climits>

#include "Utility/SDL_RectExtensions.h"

namespace nge {

    SDL_Rect Sprite::FULL_TEXTURE = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};

    Sprite::Sprite(
        std::shared_ptr<Graphics> graphics, 
        std::string texturePath, 
        SDL_Rect src, 
        SDL_Rect dst
    ) : graphics_(graphics), src_(src), dst_(dst) {
        texture_ = graphics_->LoadTexture(texturePath);
    }

    void Sprite::Draw() {
        graphics_->DrawTexture(texture_.get(), src_ == FULL_TEXTURE ? nullptr : &src_, &dst_);
    }

    int Sprite::GetX() {
        return dst_.x;
    }

    int Sprite::GetY() {
        return dst_.y;
    }
    
    Sprite::~Sprite() {

    }
}