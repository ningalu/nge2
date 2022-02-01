#include "State.h"

#include <iostream>

namespace nge {
    State::State() {

    }
    State::State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics) {
        states_ = states;
        graphics_ = graphics;
        input_ = std::make_unique<Input>();
        test = graphics_->LoadTexture("resources/stewie.jpg");
        std::cout << "State: " << this << std::endl;
    }

    void State::Tick() {
        if (input_->KeyDown(SDL_SCANCODE_A)) {
            std::cout << "A Down" << std::endl;
        }
        if (input_->KeyPressed(SDL_SCANCODE_A)) {
            std::cout << "A Pressed" << std::endl;
        }
        if (input_->KeyReleased(SDL_SCANCODE_A)) {
            std::cout << "A Released" << std::endl;
        }
        if (input_->MouseClicked(Input::kLeft)) {
            std::cout << "Left Mouse Clicked" << std::endl;
        }
        if (input_->MouseHeld(Input::kLeft)) {
            std::cout << "Left Mouse Held" << std::endl;
        }
        if (input_->MouseReleased(Input::kLeft)) {
            std::cout << "Left Mouse Released" << std::endl;
        }
        
    }

    void State::Draw() {
        std::cout << "Drawing State " << this << std::endl;
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
        std::cout << "State " << this << " Destroyed" << std::endl;
    }

}