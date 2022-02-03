#include "State.h"

#include <iostream>

namespace nge {
    State::State() {

    }
    State::State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics) {
        states_ = states;
        graphics_ = graphics;
        input_ = std::make_unique<Input>();
        default_sound_ = Audio::LoadSound("resources/default_sound.wav");
    }

    void State::Tick() {
        if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            Quit();
        }
        if (input_->MouseClicked(Input::kLeft)) {
            Audio::PlaySound(default_sound_.get());
        }
    }

    void State::Draw() {
        graphics_->DrawTexture(graphics_->LoadTexture("resources/default_texture.png").get(), nullptr, nullptr);
    }

    void State::UpdatePreviousInput(){
        input_->UpdatePrevInput();
    }

    void State::UpdateCurrentInput(){
        input_->Update();
    }
    
    void State::UpdateInput() {

    }

    void State::Quit() {
        SDL_Event quit;
        quit.type = SDL_QUIT;
        SDL_PushEvent(&quit);
    }

    State::~State() {
    }

}