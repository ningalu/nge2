#include "State.h"

#include <iostream>

namespace nge {
    State::State() {

    }
    State::State(std::shared_ptr<Graphics> graphics) {
        graphics_ = graphics;
        test = graphics_->LoadTexture("resources/stewie.jpg");
        std::cout << "State: " << graphics_.get() << std::endl;
    }

    void State::Tick() {
        
    }

    void State::Draw() {
        graphics_->DrawTexture(test.get(), nullptr, nullptr);
    }

    State::~State() {
        
    }

}