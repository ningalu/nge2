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
    // Are these initialisers worth the constructor being so insanely ugly?
    Sprite(graphics, texturePath, src, dst, angle, rotationCentre, flip),
    frame_count_(frameCount), 
    repeats_(repeats),
    frame_duration_(frameDuration),
    current_duration_(0),
    current_frame_(0),
    current_repeat_(0) {
        full_texture_ = src_;
        src_ = {0, 0, 0, 0};
        src_.w = full_texture_.w / frameCount;
        src_.h = full_texture_.h;
    }

    // Having animation updates use time deltas would probably cause weird stuttering so this version is frame dependent
    void AnimatedSprite::Draw() {
        Sprite::Draw();
        current_duration_++;
        if (current_duration_ >= frame_duration_) {
            current_duration_ = 0;
            current_frame_++;
            if (current_frame_ >= frame_count_) {
                current_frame_ = 0;
                current_repeat_++;
            }
        }
        if ((repeats_ == -1) || (current_repeat_ < repeats_)) {
            src_.x = current_frame_ * src_.w;
            src_.x %= full_texture_.w;
        }
        
    }

    void AnimatedSprite::Reset() {
        current_duration_ = 0;
        current_frame_ = 0;
        current_repeat_ = 0;
    }

    AnimatedSprite::~AnimatedSprite() {

    }
}