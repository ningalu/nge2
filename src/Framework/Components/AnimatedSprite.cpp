#include "AnimatedSprite.h"

#include <iostream>

#include "Core/Utility/SDL_RectExtensions.h"

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

        update_state_ = true;
    }

    std::shared_ptr<AnimationState> AnimatedSprite::GetAnimationState() {
        return state_;
    }

    void AnimatedSprite::SetAnimationState(std::shared_ptr<AnimationState> animationState) {
        state_ = animationState;
    }

    // Could update animations in State::Tick in order to be able to use time deltas rather than
    // depending on framerate
    // Maybe make an alternative time based animation class later on
    void AnimatedSprite::Draw() {
        Sprite::Draw();
        Advance();
    }

    void AnimatedSprite::Advance() {
        if (update_state_) {
            state_->Advance();
        }
        if ((state_->Repeats == -1) || (state_->CurrentRepeat < state_->Repeats)) {
            src_.x = state_->CurrentFrame * src_.w;
            src_.x %= full_texture_.w;
        }
    }

    void AnimatedSprite::Reset() {
        state_->Reset();
    }

    void AnimatedSprite::Sync(AnimatedSprite& sprite, bool disableAdvance) {
        if (state_->IsCompatable(*sprite.GetAnimationState())) {
            state_ = sprite.GetAnimationState();
            update_state_ = !disableAdvance;
        } // Could throw exception here
    }

    AnimatedSprite::~AnimatedSprite() {

    }
}