#ifndef _TEXT_H
#define _TEXT_H

#include "Components/Utility/SimpleDrawableBase.h"

#include "SDL2/SDL.h"

#include "Core/Graphics.h"

namespace nge {
    class Text : public SimpleDrawableBase {
        public:
            Text() = default;
            Text(
                std::shared_ptr<Graphics> graphics, 
                FontPtr font, 
                FontStyle style,
                const std::string& text, 
                SDL_Point dst, 
                SDL_Color colour = {0, 0, 0, 0},
                SDL_Color bg = {0, 0, 0, 255},
                double angle = 0.0f,
                SDL_Point rotationCentre = Graphics::ROTATION_CENTRE,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );

            // Drawable Interface
            void Draw();

            ~Text();

        protected:
            std::shared_ptr<Graphics> graphics_;
            TexturePtr texture_;
            SDL_RendererFlip flip_;
    };
    
    using TextPtr = std::unique_ptr<Text>;
}

#endif