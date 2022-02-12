#include "Graphics.h"

#include <iostream>

#include "SDL2/SDL.h"

namespace nge {
    Graphics::Graphics(std::string title, SDL_Rect windowRect) : 
        window_(nullptr, SDL_DestroyWindow),
        renderer_(nullptr, SDL_DestroyRenderer),
        title_(title)
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
            windowRect.x,
            windowRect.y,
            windowRect.w,
            windowRect.h,
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

    TexturePtr Graphics::LoadTexture(std::string path) {
        TexturePtr t;
        SDL_Surface *tempSurf = IMG_Load(path.c_str());
        if (tempSurf == nullptr) {
            std::cout << "LoadTexture: Surface could not be created from: " << path << std::endl;
            return t;
        }
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer_.get(), tempSurf);
        if (texture == nullptr) {
            std::cout << "LoadTexture: Texture could not be created from SDL_Renderer* " << renderer_.get() << " and SDL_Surface* " << tempSurf << std::endl;
            return t;
        }
        SDL_FreeSurface(tempSurf);
        return TexturePtr(texture, [](SDL_Texture* tex){
            SDL_DestroyTexture(tex);
        });
    }

    void Graphics::Clear() {
        SDL_RenderClear(renderer_.get());
    }

    void Graphics::DrawTexture(
        SDL_Texture* const texture, 
        const SDL_Rect* const src, 
        const SDL_Rect* const dst, 
        double angle,
        SDL_Point* rotationCentre,
        SDL_RendererFlip flip
    ) {
        SDL_RenderCopyEx(renderer_.get(), texture, src, dst, angle, rotationCentre, flip);
    }

    void Graphics::Present() {
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

    SDL_Renderer* Graphics::GetRenderer() {
        return renderer_.get();
    }
    
    Graphics::~Graphics() {
    }
}