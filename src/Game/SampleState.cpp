#include "SampleState.h"

#include <iostream>

SampleState::SampleState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics) : State(states, graphics) {
    sprite1_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/stewie.jpg", nge::Sprite::FULL_TEXTURE, {100, 100, 100, 100}));
    sprite2_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/ibuki.png", nge::Sprite::FULL_TEXTURE, {300, 400, 160, 206}));
}

void SampleState::Tick() {
    if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
        states_->Return();
    }
    if (input_->KeyPressed(SDL_SCANCODE_SPACE)) {
        states_->Advance(std::shared_ptr<State>(new nge::State(states_, graphics_)));
    }
    sprite1_->SetX(input_->GetMouseX() - 50);
    sprite1_->SetY(input_->GetMouseY() - 50);
    if (input_->KeyDown(SDL_SCANCODE_W)) {
        sprite2_->MoveY(-1);
    }
    if (input_->KeyDown(SDL_SCANCODE_S)) {
        sprite2_->MoveY(1);
    }
    if (input_->KeyDown(SDL_SCANCODE_A)) {
        sprite2_->MoveX(-1);
    }
    if (input_->KeyDown(SDL_SCANCODE_D)) {
        sprite2_->MoveX(1);
    }
    
}

void SampleState::Draw() {
    sprite1_->Draw();
    sprite2_->Draw();
}

SampleState::~SampleState() {

}