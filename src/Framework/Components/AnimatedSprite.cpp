#include "AnimatedSprite.h"

#include <iostream>

#include "Utility/SDL_RectExtensions.h"

namespace nge {
    AnimatedSprite::AnimatedSprite(
        std::shared_ptr<Graphics> graphics, 
        std::string texturePath, 
        SDL_Rect src, 
        SDL_Rect dst,
        int frameCount,
        int repeats,
        double frameDuration,
        double angle,
        SDL_Point rotationCentre,
        SDL_RendererFlip flip
    ) : 
    Sprite(graphics, texturePath, src, dst, angle, rotationCentre, flip),
    frame_count_(frameCount), 
    repeats_(repeats),
    frame_duration_(frameDuration) {
        full_texture_ = src_;
        src_ = {0, 0, 0, 0};
        src_.w = full_texture_.w / frameCount;
        src_.h = full_texture_.h;
    }

    void AnimatedSprite::Draw() {
        Sprite::Draw();
    }

    AnimatedSprite::~AnimatedSprite() {

    }
}