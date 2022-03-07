#ifndef _COMPONENTS_SPRITE_H
#define _COMPONENTS_SPRITE_H

#include "Components/Utility/SimpleDrawableBase.h"

#include <string>

#include "SDL2/SDL.h"

#include "Core/Graphics.h"

namespace nge {

    class Sprite : public SimpleDrawableBase {
        public:
            Sprite() = default;
            Sprite(
                std::shared_ptr<Graphics> graphics, 
                std::string texturePath, 
                SDL_Rect src, 
                SDL_Rect dst,
                double angle = 0.0f,
                SDL_Point rotationCentre = Graphics::ROTATION_CENTRE,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );

            void Draw();

            ~Sprite();

        protected:
            std::shared_ptr<Graphics> graphics_;
            TexturePtr texture_;
            SDL_RendererFlip flip_;
    };

    using SpritePtr = std::unique_ptr<Sprite>;
}

#endif