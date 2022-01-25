#include "stdio.h"
#include <iostream>

#include "Game.h"

int main(int argc, char **argv) {

    std::cout << "Starting" << std::endl;

    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }

    nge::Game game;
    game.Start();

    std::cout << "initial commit" << std::endl;

    return 0;
}