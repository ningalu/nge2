#include "Sprite.h"

#include <climits>
#include <iostream>

#include "Core/Utility/SDL_RectExtensions.h"
#include "Core/Utility/SDL_PointExtensions.h"

namespace nge {
    Sprite::Sprite(
        std::shared_ptr<Graphics> graphics, 
        std::string texturePath, 
        SDL_Rect src, 
        SDL_Rect dst,
        double angle,
        SDL_Point rotationCentre,
        SDL_RendererFlip flip
    ) : graphics_(graphics), flip_(flip) {
        dst_ = dst;
        angle_ = angle;
        texture_ = graphics_->LoadTexture(texturePath);
        if (src == Graphics::FULL_TEXTURE) {
            src_.x = 0;
            src_.y = 0;
            SDL_QueryTexture(texture_.get(), nullptr, nullptr, &src_.w, &src_.h);
        } else {
            src_ = src;
        }
        if (rotationCentre == Graphics::ROTATION_CENTRE) {
            rotation_centre_.x = dst_.w / 2;
            rotation_centre_.y = dst_.h / 2;
        } else {
            rotation_centre_ = rotationCentre;
        }
    }
    Sprite::Sprite(
        std::shared_ptr<Graphics> graphics, 
        TexturePtr texture,
        SDL_Rect src, 
        SDL_Rect dst,
        double angle,
        SDL_Point rotationCentre,
        SDL_RendererFlip flip
    ) : graphics_(graphics), texture_(texture), flip_(flip) {
        dst_ = dst;
        angle_ = angle;

        if (src == Graphics::FULL_TEXTURE) {
            src_.x = 0;
            src_.y = 0;
            SDL_QueryTexture(texture_.get(), nullptr, nullptr, &src_.w, &src_.h);
        } else {
            src_ = src;
        }

        if (rotationCentre == Graphics::ROTATION_CENTRE) {
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

    Sprite::~Sprite() {
    }
}