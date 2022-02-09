#ifndef _ANIMATEDSPRITE_H
#define _ANIMATEDSPRITE_H

#include "Sprite.h"

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
                double frameDuration = 1,
                double angle = 0.0f,
                SDL_Point rotationCentre = ROTATION_CENTRE,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );

            void Draw() override;
            void Advance();
            void Reset();

            ~AnimatedSprite();

        protected:
            int frame_count_;
            int repeats_;
            double frame_duration_;
            SDL_Rect full_texture_;

            int current_duration_;
            int current_frame_;
            int current_repeat_;

            void UpdateFrame();
    };

    using AnimatedSpritePtr = std::unique_ptr<AnimatedSprite>;
    using AnimPtr = std::unique_ptr<AnimatedSprite>;
}

#endif