#include "stdio.h"
#include <iostream>

#include "SDL2/SDL.h"

#include "Game.h"

int main(int argc, char **argv) {

    std::cout << "Starting" << std::endl;

    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }

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

    nge::Game game;
    game.Start();

    std::cout << "initial commit" << std::endl;

    return 0;
}