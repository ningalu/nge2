#include "stdio.h"
#include <iostream>
#include <mutex>

#include "nlohmann/json.hpp"
#include "sigslot/signal.hpp"

#include "Core/Game.hpp"
#include "Core/Timer.h"
#include "Core/Utility/SDL_RectExtensions.h"

#include "InitialState/InitialState.h"
#include "SampleState.h"
#include "MiningState/MiningState.h"

int main(int argc, char **argv) {
    
    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }

    nlohmann::json j;
    sigslot::signal<int> s;
    s(9);
    
    nge::Game game;
    // auto s = std::make_shared<SampleState>(game.GetStateManager(), game.GetGraphics());
    // auto s = new SampleState(game.GetStateManager(), game.GetGraphics());
    // std::cout << "Initial State: " << s << std::endl;
    // game.Start(new SampleState(game.GetStateManager(), game.GetGraphics()));

    game.SetInitialState<MiningState>();
    game.Start();
    

    return 0;
}