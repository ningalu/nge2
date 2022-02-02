#include "State.h"

#include <iostream>

namespace nge {
    State::State() {

    }
    State::State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics) {
        states_ = states;
        graphics_ = graphics;
        input_ = std::make_unique<Input>();
        test = graphics_->LoadTexture("resources/override_error.png");
    }

    void State::Tick() {
        if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            SDL_Event quit;
            quit.type = SDL_QUIT;
            SDL_PushEvent(&quit);
        }
    }

    void State::Draw() {
        graphics_->DrawTexture(test.get(), nullptr, nullptr);
    }

    void State::UpdatePreviousInput(){
        input_->UpdatePrevInput();
    }

    void State::UpdateCurrentInput(){
        input_->Update();
    }
    
    void State::UpdateInput() {

    }

    State::~State() {
    }

}