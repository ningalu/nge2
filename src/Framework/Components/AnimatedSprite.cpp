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
        int frameDuration,
        double angle,
        SDL_Point rotationCentre,
        SDL_RendererFlip flip
    ) : 
    Sprite(graphics, texturePath, src, dst, angle, rotationCentre, flip) {
        state_ = std::make_shared<AnimationState>(frameCount, repeats, frameDuration);
        full_texture_ = src_;
        src_ = {0, 0, 0, 0};
        src_.w = full_texture_.w / state_->FrameCount;
        src_.h = full_texture_.h;

    }

    // Having animation updates use time deltas would probably cause weird stuttering so this version is frame dependent
    void AnimatedSprite::Draw() {
        Sprite::Draw();
        Advance();
    }

    void AnimatedSprite::Advance() {
        state_->Advance();
        if ((state_->Repeats == -1) || (state_->CurrentRepeat < state_->Repeats)) {
            src_.x = state_->CurrentFrame * src_.w;
            src_.x %= full_texture_.w;
        }
    }

    void AnimatedSprite::Reset() {
        state_->Reset();
    }

    AnimatedSprite::~AnimatedSprite() {

    }
}