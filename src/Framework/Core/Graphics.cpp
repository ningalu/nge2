#include "Graphics.h"

#include <iostream>

namespace nge {
    Graphics::Graphics() : 
        window_(nullptr, SDL_DestroyWindow),
        renderer_(nullptr, SDL_DestroyRenderer)
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cout << "Error initialising SDL2: " << SDL_GetError() << std::endl;
            return;
        }

        int IMG_Flags = IMG_INIT_JPG | IMG_INIT_PNG;
        if (!(IMG_Init(IMG_Flags) & IMG_Flags)) {
            std::cout << "Error initialising SDL_image: " << IMG_GetError() << std::endl;
            return;
        }        

        if (TTF_Init() != 0) {
            std::cout << "Error initialising SDL_ttf: " << TTF_GetError() << std::endl;
            return;
        }

        SDL_Window *window = SDL_CreateWindow(
            "NGE2 Demo",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800,
            600,
            0
        );
        if (window == nullptr) {
            std::cout << "Error creating window: " << SDL_GetError() << std::endl;
            return;
        } else {
            window_.reset(window);
        }

        SDL_Renderer *renderer = SDL_CreateRenderer(
            window_.get(),
            -1,
            0
        );
        if (renderer == nullptr) {
            std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
            return;
        } else {
            renderer_.reset(renderer);
        }
    }

    void Graphics::Clear() {
        SDL_RenderClear(renderer_.get());
    }

    void Graphics::Present() {
        SDL_RenderPresent(renderer_.get());
    }

    Graphics::~Graphics() {

    }
}