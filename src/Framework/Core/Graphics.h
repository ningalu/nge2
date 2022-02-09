#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <memory>
#include <string>
#include <functional>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

namespace nge {
    using TexturePtr = std::shared_ptr<SDL_Texture>;

    class Graphics {
        public:
            Graphics(std::string title, SDL_Rect windowRect);

            TexturePtr LoadTexture(std::string path);
            void Clear();
            void DrawTexture(
                SDL_Texture* const texture, 
                const SDL_Rect* const src, 
                const SDL_Rect* const dst, 
                double angle = 0.0f,
                SDL_Point* rotationCentre = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE
            );
            void Present();

            void SetWindowSize(int w, int h);
            int GetWindowWidth() const;
            int GetWindowHeight() const;

            void SetWindowPosition(int x, int y);
            int GetWindowX() const;
            int GetWindowY() const;

            void SetWindowRect(SDL_Rect window);
            SDL_Rect GetWindowRect() const;

            SDL_Renderer* GetRenderer();

            ~Graphics();

        private:
            std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;
            std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;
            std::string title_;
    };
}

#endif