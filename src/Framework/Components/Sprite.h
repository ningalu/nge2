#ifndef _SPRITE_H
#define _SPRITE_H

#include "GraphicsInterfaces/Drawable.h"
#include "GraphicsInterfaces/Translatable.h"
#include "GraphicsInterfaces/Rotatable.h"

#include <string>

#include "SDL2/SDL.h"

#include "Graphics.h"

namespace nge {

    class Sprite : public Drawable, public Translatable, public Rotatable {
        public:
            Sprite(
                std::shared_ptr<Graphics> graphics, 
                std::string texturePath, 
                SDL_Rect src, 
                SDL_Rect dst,
                double angle = 0.0f,
                SDL_Point rotationCentre = ROTATION_CENTRE,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );
            
            const static SDL_Rect FULL_TEXTURE;
            const static SDL_Point ROTATION_CENTRE;

            // Drawable Interface
            void Draw() override;
            int GetX() override;
            int GetY() override;

            // Translatable Interface
            void SetX(int x);
            void SetY(int y);
            void MoveX(int x);
            void MoveY(int y);

            // Rotatable Interface
            double GetAngle();
            void Rotate(double angle);
            void SetAngle(double angle);

            ~Sprite();

        protected:
            std::shared_ptr<Graphics> graphics_;
            TexturePtr texture_;
            SDL_Rect src_;
            SDL_Rect dst_;
            double angle_;
            SDL_Point rotation_centre_;
            SDL_RendererFlip flip_;
    };

    using SpritePtr = std::unique_ptr<Sprite>;
}

#endif