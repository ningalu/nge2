#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <memory>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

namespace nge {
    class Graphics {
        public:
            Graphics();

            std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> LoadTexture(std::string path);
            void Clear();
            void DrawTexture(SDL_Texture* const texture, const SDL_Rect* const src, const SDL_Rect* const dst);
            void Present();

            void SetWindowSize(int w, int h);
            int GetWindowWidth() const;
            int GetWindowHeight() const;

            void SetWindowPosition(int x, int y);
            int GetWindowX() const;
            int GetWindowY() const;

            void SetWindowRect(SDL_Rect window);
            SDL_Rect GetWindowRect() const;

            ~Graphics();

        private:
            std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;
            std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;
    };
}

#endif