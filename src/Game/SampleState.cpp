#include "SampleState.h"

#include <iostream>

SampleState::SampleState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics) : State(states, graphics) {
    sprite_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/stewie.jpg", nge::Sprite::FULL_TEXTURE, {100, 100, 100, 100}));
}

void SampleState::Tick() {
    if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
        states_->Return();
    }
    if (input_->KeyPressed(SDL_SCANCODE_A)) {
        states_->Advance(std::shared_ptr<State>(new nge::State(states_, graphics_)));
    }
    sprite_->SetX(input_->GetMouseX());
    sprite_->SetY(input_->GetMouseY());
}

void SampleState::Draw() {
    sprite_->Draw();
}

SampleState::~SampleState() {

}