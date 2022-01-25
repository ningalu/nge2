#include "Game.h"
#include <iostream>

using namespace nge;

Game::Game() {
    running_ = false;
    timer_.Start();
}

void Game::Start() {
    running_ = true;

    std::cout << "SDL Init from Game.cpp" << std::endl;
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    while (true) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}

bool Game::IsRunning() {
    return running_;
}

void Game::End() {
    running_ = false;
}

Game::~Game() {

}

void Game::PreDrawUpdate() {

}

void Game::Draw() {

}

void Game::PostDrawUpdate() {

}