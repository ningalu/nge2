#include "SampleState.h"

#include <iostream>

SampleState::SampleState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics) : State(states, graphics) {
    sprite1_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/stewie.jpg", nge::Sprite::FULL_TEXTURE, {100, 100, 100, 100}));
    sprite2_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/ibuki.png", nge::Sprite::FULL_TEXTURE, {300, 400, 160, 206}));
    anim1_ = nge::AnimPtr(new nge::AnimatedSprite(graphics_, "resources/blaziken_anim_test.png", nge::Sprite::FULL_TEXTURE, {50, 50, 100, 100}, 17));
    draw_timer_.Start();
}

void SampleState::Tick() {
    if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
        states_->Return();
    }
    if (input_->KeyPressed(SDL_SCANCODE_SPACE)) {
        states_->Advance(std::shared_ptr<State>(new nge::State(states_, graphics_)));
    }
    
    
}

void SampleState::Draw() {
    double dt = draw_timer_.GetElapsedTime();
    sprite1_->SetX(input_->GetMouseX() - 50);
    sprite1_->SetY(input_->GetMouseY() - 50);
    if (input_->KeyDown(SDL_SCANCODE_W)) {
        sprite2_->MoveY(-120 * dt);
    }
    if (input_->KeyDown(SDL_SCANCODE_S)) {
        sprite2_->MoveY(120 * dt);
    }
    if (input_->KeyDown(SDL_SCANCODE_A)) {
        sprite2_->MoveX(-120 * dt);
    }
    if (input_->KeyDown(SDL_SCANCODE_D)) {
        sprite2_->MoveX(120 * dt);
    }
    if (input_->KeyDown(SDL_SCANCODE_Q)) {
        sprite2_->Rotate(-100.0 * dt);
    }
    if (input_->KeyDown(SDL_SCANCODE_E)) {
        sprite2_->Rotate(100.0 * dt);
    }
    sprite1_->Draw();
    sprite2_->Draw();
    anim1_->Draw();
    draw_timer_.Reset();

}

SampleState::~SampleState() {

}