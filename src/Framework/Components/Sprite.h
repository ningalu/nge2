#ifndef _SPRITE_H
#define _SPRITE_H

#include "GraphicsInterfaces/Drawable.h"

#include <string>

#include "SDL2/SDL.h"

#include "Graphics.h"

namespace nge {
    
    class Sprite : public Drawable {
        public:
            Sprite(
                std::shared_ptr<Graphics> graphics, 
                std::string texturePath, 
                SDL_Rect src, 
                SDL_Rect dst
            );

            void Draw() override;

            ~Sprite();

        protected:
            std::shared_ptr<Graphics> graphics_;
            TexturePtr texture_;
            SDL_Rect src_;
            SDL_Rect dst_;
    };

    using SpritePtr = std::unique_ptr<Sprite>;
}

#endif