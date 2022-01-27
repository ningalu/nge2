#include "Graphics.h"

#include <iostream>

#include "SDL2/SDL.h"

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

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> Graphics::LoadTexture(std::string path) {
        SDL_Surface *tempSurf = IMG_Load(path.c_str());
        if (tempSurf == nullptr) {
            std::cout << "LoadTexture: Surface could not be created from: " << path << std::endl;
            return std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>(nullptr, SDL_DestroyTexture);
        }
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer_.get(), tempSurf);
        if (texture == nullptr) {
            std::cout << "LoadTexture: Texture could not be created from SDL_Renderer* " << renderer_.get() << " and SDL_Surface* " << tempSurf << std::endl;
            return std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>(nullptr, SDL_DestroyTexture);
        }
        SDL_FreeSurface(tempSurf);
        return std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>(texture, SDL_DestroyTexture);
    }

    void Graphics::Clear() {
        SDL_RenderClear(renderer_.get());
    }

    void Graphics::DrawTexture(SDL_Texture* const texture, const SDL_Rect* const src, const SDL_Rect* const dst) {
        SDL_RenderCopy(renderer_.get(), texture, src, dst);
    }

    void Graphics::Present() {
        SDL_Rect a = {0, 0, 50, 50};
        DrawTexture(LoadTexture("resources/stewie.jpg").get(), nullptr, &a);
        SDL_RenderPresent(renderer_.get());
    }

    void Graphics::SetWindowSize(int w, int h){
        SDL_SetWindowSize(window_.get(), w, h);
    }

    int Graphics::GetWindowWidth() const {
        int w;
        SDL_GetWindowSize(window_.get(), &w, nullptr);
        return w;
    }

    int Graphics::GetWindowHeight() const {
        int h;
        SDL_GetWindowSize(window_.get(), nullptr, &h);
        return h;
    }
    
    void Graphics::SetWindowPosition(int x, int y) {
        SDL_SetWindowPosition(window_.get(), x, y);
    }

    int Graphics::GetWindowX() const {
        int x;
        SDL_GetWindowPosition(window_.get(), &x, nullptr);
        return x;
    }

    int Graphics::GetWindowY() const {
        int y;
        SDL_GetWindowPosition(window_.get(), nullptr, &y);
        return y;
    }
    
    void Graphics::SetWindowRect(SDL_Rect window) {
        SetWindowPosition(window.x, window.y);
        SetWindowSize(window.w, window.h);
    }

    SDL_Rect Graphics::GetWindowRect() const {
        SDL_Rect window;
        SDL_GetWindowPosition(window_.get(), &window.x, &window.y);
        SDL_GetWindowSize(window_.get(), &window.w, &window.h);
        return window;
    }
    
    Graphics::~Graphics() {

    }
}