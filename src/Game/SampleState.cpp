#include "SampleState.h"

#include <iostream>

#include "Utility/SDL_RectExtensions.h"

SampleState::SampleState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics) : State(states, graphics) {

    // 1 doesn't require the user knows the actual type of WhateverPtr, but you kinda want to be using make_shared when applicable
    // 1. sprite1_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/stewie.jpg", nge::Sprite::FULL_TEXTURE, {100, 100, 100, 100}));
    // 2. butt1_ = std::make_shared<nge::Button>(input_, std::move(temp), SDL_Rect{300, 50, 250, 250});

    sprite1_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/SampleState/stewie.jpg", nge::Sprite::FULL_TEXTURE, {100, 100, 100, 100}));

    sprite2_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/SampleState/ibuki.png", nge::Sprite::FULL_TEXTURE, {300, 400, 160, 206}));

    anim1_ = nge::AnimPtr(new nge::AnimatedSprite(graphics_, "resources/SampleState/blaziken_anim_test.png", nge::Sprite::FULL_TEXTURE, {50, 50, 100, 100}, 17, 2, 2));

    nge::SpritePtr temp = std::make_unique<nge::Sprite>(graphics_, "resources/SampleState/hachigatsu.jpg", nge::Sprite::FULL_TEXTURE, SDL_Rect{300, 50, 250, 250});

    nge::SpritePtr tempHeld = std::make_unique<nge::Sprite>(graphics_, "resources/SampleState/hachigatsu_held.jpg", nge::Sprite::FULL_TEXTURE, SDL_Rect{300, 50, 250, 250});

    butt1_ = std::make_shared<nge::Button>(input_, std::move(temp), SDL_Rect{300, 50, 250, 250});
    butt1_->SetHeldDrawable(std::move(tempHeld));
    butt1_->SetOnRelease([&](){
        std::cout << "Released from lambda" << std::endl;
        if (std::shared_ptr<nge::StateManager> sm = states_.lock()) {
            std::cout << "Locked" << std::endl;
            sm->Advance(std::make_shared<State>(sm, graphics_));
        }
    });

    RegisterClickable(butt1_);

    anim2_ = std::make_unique<nge::AnimatedSprite>(graphics_, "resources/kokichiwalk.png", nge::Sprite::FULL_TEXTURE, SDL_Rect{600, 600, 89, 90}, 2, -1, 15);

    RegisterKeyEvent(SDL_SCANCODE_W, nge::InputState::PRESSED | nge::InputState::HELD, [&](){
        sprite2_->MoveY(-100 * draw_timer_.GetElapsedTime());
    });
    RegisterKeyEvent(SDL_SCANCODE_A, nge::InputState::PRESSED | nge::InputState::HELD, [&](){
        sprite2_->MoveX(-100 * draw_timer_.GetElapsedTime());
    });
    RegisterKeyEvent(SDL_SCANCODE_S, nge::InputState::PRESSED | nge::InputState::HELD, [&](){
        sprite2_->MoveY(100 * draw_timer_.GetElapsedTime());
    });
    RegisterKeyEvent(SDL_SCANCODE_D, nge::InputState::PRESSED | nge::InputState::HELD, [&](){
        sprite2_->MoveX(100 * draw_timer_.GetElapsedTime());
    });

    draw_timer_.Start();
}

void SampleState::Tick() {
    if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
        active_ = false;
    }
    if (input_->KeyPressed(SDL_SCANCODE_SPACE)) {
        if (std::shared_ptr<nge::StateManager> sm = states_.lock()) {
            sm->Advance(std::make_shared<State>(sm, graphics_));
        }
    }
    if (input_->KeyPressed(SDL_SCANCODE_U)) {
        if (std::shared_ptr<nge::StateManager> sm = states_.lock()) {
            sm->Advance(std::make_shared<SampleState>(sm, graphics_));
        }
    }
    if (input_->KeyPressed(SDL_SCANCODE_RETURN)) {
        anim1_->Reset();
    }
}

void SampleState::Draw() {
    double dt = draw_timer_.GetElapsedTime();
    sprite1_->SetX(input_->GetMouseX() - 50);
    sprite1_->SetY(input_->GetMouseY() - 50);
    if (input_->KeyHeld(SDL_SCANCODE_Q)) {
        sprite2_->Rotate(-100.0 * dt);
    }
    if (input_->KeyHeld(SDL_SCANCODE_E)) {
        sprite2_->Rotate(100.0 * dt);
    }
    
    sprite1_->Draw();
    sprite2_->Draw();
    anim1_->Draw();
    butt1_->Draw();
    anim2_->Draw();
    draw_timer_.Reset();
}

SampleState::~SampleState() {
}