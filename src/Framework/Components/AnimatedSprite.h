#ifndef _ANIMATEDSPRITE_H
#define _ANIMATEDSPRITE_H

#include "Sprite.h"
#include "Utility/AnimationState.h"

namespace nge {
    class AnimatedSprite : public Sprite {
        public:
            AnimatedSprite(
                std::shared_ptr<Graphics> graphics, 
                std::string texturePath, 
                SDL_Rect src, 
                SDL_Rect dst,
                int frameCount,
                int repeats = -1,
                int frameDuration = 1,
                double angle = 0.0f,
                SDL_Point rotationCentre = Graphics::ROTATION_CENTRE,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );

            std::shared_ptr<AnimationState> GetAnimationState();
            void SetAnimationState(std::shared_ptr<AnimationState> animationState);

            void Draw() override;
            void Advance();
            void Reset();
            void Sync(AnimatedSprite& sprite, bool disableAdvance = true);
            

            ~AnimatedSprite();

        protected:
            std::shared_ptr<AnimationState> state_;
            SDL_Rect full_texture_;
            bool update_state_;
    };

    using AnimatedSpritePtr = std::unique_ptr<AnimatedSprite>;
    using AnimPtr = std::unique_ptr<AnimatedSprite>;
}

#endif