#include "stdio.h"
#include <iostream>

#include "Game.h"
#include "Timer.h"

int main(int argc, char **argv) {
    
    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }

    nge::Game game;
    game.Start();

    return 0;
}