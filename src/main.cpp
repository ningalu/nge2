#include "stdio.h"
#include <iostream>

#include "Core/Game.hpp"
#include "Core/Timer.h"

#include "InitialState/InitialState.h"
#include "SampleState.h"
#include "Utility/SDL_RectExtensions.h"
#include "SDL_RectExtensionsTests.h"

int main(int argc, char **argv) {
    
    if (RunSDL_RectExtensionTests() == TestResult::FAIL) {
        return 1;
    } else {
        std::cout << "SDL_RectExtensionTests ran successfully" << std::endl;
    }

    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }
    
    nge::Game game;
    // auto s = std::make_shared<SampleState>(game.GetStateManager(), game.GetGraphics());
    // auto s = new SampleState(game.GetStateManager(), game.GetGraphics());
    // std::cout << "Initial State: " << s << std::endl;
    // game.Start(new SampleState(game.GetStateManager(), game.GetGraphics()));

    game.SetInitialState<InitialState>();
    game.Start();
    

    return 0;
}