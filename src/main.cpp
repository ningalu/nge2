#include "stdio.h"
#include <iostream>

#include "Core/Game.hpp"
#include "Core/Timer.h"

#include "InitialState/InitialState.h"
#include "SampleState.h"
#include "Utility/SDL_RectExtensions.h"
#include "SDL_RectExtensionsTests.h"

class Interface {
    public:
        virtual int X() = 0;
};

class Base : public Interface {
    public:
        int x;
        virtual int X() {
            return x;
        }
};

class Impl : public Base {

};

int main(int argc, char **argv) {
    
    for (int i = 0; i < argc - 1; i++) {
        printf("%d\n", argv[i]);
    }
    
    if (RunSDL_RectExtensionTests() == TestResult::FAIL) {
        return 1;
    } else {
        std::cout << "SDL_RectExtensionTests ran successfully" << std::endl;
    }

    Impl i;
    i.x = 0;
    std::cout << i.X() << std::endl;

    Base *b = new Impl();
    b->x = 0;
    std::cout << b->X() << std::endl;

    Interface *I = new Impl();
    std::cout << I->X() << std::endl;
    
    
    nge::Game game;
    // auto s = std::make_shared<SampleState>(game.GetStateManager(), game.GetGraphics());
    // auto s = new SampleState(game.GetStateManager(), game.GetGraphics());
    // std::cout << "Initial State: " << s << std::endl;
    // game.Start(new SampleState(game.GetStateManager(), game.GetGraphics()));

    game.SetInitialState<InitialState>();
    game.Start();
    

    return 0;
}