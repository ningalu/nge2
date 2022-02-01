#include "State.h"

#include <iostream>

namespace nge {
    State::State() {

    }
    State::State(std::shared_ptr<Graphics> graphics) {
        graphics_ = graphics;
        test = graphics_->LoadTexture("resources/stewie.jpg");
        std::cout << "State: " << this << std::endl;
    }

    void State::Tick() {
        
    }

    void State::Draw() {
        std::cout << "Drawing State " << this << std::endl;
        graphics_->DrawTexture(test.get(), nullptr, nullptr);
    }

    void State::UpdateInput() {

    }

    State::~State() {
        std::cout << "State " << this << " Destroyed" << std::endl;
    }

}