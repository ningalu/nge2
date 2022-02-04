#include "stdio.h"
#include <iostream>

#include "Core/Game.h"
#include "Core/Timer.h"

#include "SampleState.h"

int main(int argc, char **argv) {
    
    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }

    nge::Game game;
    game.Start(new SampleState(game.GetStateManager(), game.GetGraphics()));

    return 0;
}