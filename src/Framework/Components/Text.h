#ifndef _TEXT_H
#define _TEXT_H

#include "Interfaces/Drawable.h"
#include "Interfaces/Translatable.h"
#include "Interfaces/Rotatable.h"

#include "SDL2/SDL.h"

#include "Graphics.h"

namespace nge {
    class Text : public Drawable, public Translatable, public Rotatable {
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
            int GetX();
            int GetY();
            int GetW();
            int GetH();
            SDL_Rect GetDestRect();

            // Translatable Interface
            void SetX(int x);
            void SetY(int y);
            void MoveX(int x);
            void MoveY(int y);

            // Rotatable Interface
            double GetAngle();
            void Rotate(double angle);
            void SetAngle(double angle);

            ~Text();

        protected:
            std::shared_ptr<Graphics> graphics_;
            TexturePtr texture_;
            SDL_Rect src_, dst_;
            double angle_;
            SDL_Point rotation_centre_;
            SDL_RendererFlip flip_;
    };
    
    using TextPtr = std::unique_ptr<Text>;
}

#endif