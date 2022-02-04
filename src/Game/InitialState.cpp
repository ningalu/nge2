#include "InitialState.h"

#include <iostream>

InitialState::InitialState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics) : State(states, graphics) {
    sprite_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/stewie.jpg", nge::Sprite::FULL_TEXTURE, {100, 100, 100, 100}));
}

void InitialState::Tick() {
    if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
        states_->Return();
    }
    if (input_->KeyPressed(SDL_SCANCODE_A)) {
        states_->Advance(std::shared_ptr<State>(new nge::State(states_, graphics_)));
    }
}

void InitialState::Draw() {
    sprite_->Draw();
}

InitialState::~InitialState() {

}