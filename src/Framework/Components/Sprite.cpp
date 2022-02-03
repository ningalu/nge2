#include "Sprite.h"

namespace nge {
    Sprite::Sprite(
        std::shared_ptr<Graphics> graphics, 
        std::string texturePath, 
        SDL_Rect src, 
        SDL_Rect dst
    ) : graphics_(graphics), src_(src), dst_(dst) {
        texture_ = graphics_->LoadTexture(texturePath);
    }

    void Sprite::Draw() {
        graphics_->DrawTexture(texture_.get(), &src_, &dst_);
    }

    Sprite::~Sprite() {

    }
}