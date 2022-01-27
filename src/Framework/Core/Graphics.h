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
            void Present();

            ~Graphics();

        private:
            std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;
            std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;
    };
}

#endif