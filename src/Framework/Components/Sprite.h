#ifndef _SPRITE_H
#define _SPRITE_H

#include "SimpleDrawableBase.h"

#include <string>

#include "SDL2/SDL.h"

#include "Graphics.h"

namespace nge {

    class Sprite : public SimpleDrawableBase {
        public:
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