#include "Game.h"
#include <iostream>

using namespace nge;

Game::Game() {
    running_ = false;
}

void Game::Start() {
    running_ = true;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
    Mix_Init(MIX_INIT_FLAC);
    TTF_Init();
    SDL_Window *window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    while (running_) {
        if (tick_timer_.GetElapsedTime() > (1.0 / 1000)) {
            Tick();
            tick_timer_.Reset();
        }
        if (draw_timer_.GetElapsedTime() > (1.0f / 60)) {
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            Draw();
            draw_timer_.Reset();
        }
        
    }
}

bool Game::IsRunning() {
    return running_;
}

void Game::End() {
    running_ = false;
}

void Game::Tick() {

}

void Game::Draw() {
    
}

Game::~Game() {

}