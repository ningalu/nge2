#include "stdio.h"
#include <iostream>
#include <mutex>

#include "Core/Game.hpp"
#include "Core/Timer.h"
#include "Core/Utility/SDL_RectExtensions.h"

#include "InitialState/InitialState.h"
#include "SampleState.h"
#include "MiningState/MiningState.h"

int main(int argc, char **argv) {
    
    for (int i = 0; i < argc - 1; i++) {
        printf("%s\n", argv[i]);
    }
    
    nge::Game game;
    // auto s = std::make_shared<SampleState>(game.GetStateManager(), game.GetGraphics());
    // auto s = new SampleState(game.GetStateManager(), game.GetGraphics());
    // std::cout << "Initial State: " << s << std::endl;
    // game.Start(new SampleState(game.GetStateManager(), game.GetGraphics()));

    game.SetInitialState<MiningState>();
    game.Start();
    
    return 0;
}