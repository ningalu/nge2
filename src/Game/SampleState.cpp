#include "SampleState.h"

#include <iostream>

#include "Utility/SDL_RectExtensions.h"

SampleState::SampleState(nge::State init) : nge::State(init) {

    // 1 doesn't require the user knows the actual type of WhateverPtr, but you kinda want to be using make_shared when applicable
    // 1. sprite1_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/stewie.jpg", nge::Sprite::FULL_TEXTURE, {100, 100, 100, 100}));
    // 2. butt1_ = std::make_shared<nge::Button>(input_, std::move(temp), SDL_Rect{300, 50, 250, 250});

    nge::Timer ctorTimer;

    ctorTimer.Start();
    tileset1_ = std::make_shared<rpg::Tileset>(graphics_, "resources/OverworldState/tileset.png", 32, 32);
    std::cout << "tileset time: " << ctorTimer << std::endl;
    
    std::vector<std::vector<int>> tileIds1;
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});
    tileIds1.push_back({1, 1, 1, 1, 1, 1, 1});

    ctorTimer.Reset();
    tilemap1_ = rpg::Tilemap{graphics_, tileset1_, tileIds1};
    std::cout << "map 1 time: " << ctorTimer << std::endl;

    std::vector<std::vector<int>> tileIds2;
    tileIds2.push_back({0, 0, 30, 31, 0, 0, 0});
    tileIds2.push_back({0, 0, 38, 39, 0, 0, 0});
    tileIds2.push_back({0, 0, 0, 0, 0, 0, 0});
    tileIds2.push_back({0, 0, 0, 0, 0, 0, 0});
    tileIds2.push_back({0, 0, 0, 0, 0, 0, 0});
    tileIds2.push_back({0, 0, 0, 0, 0, 0, 0});
    tileIds2.push_back({0, 0, 0, 0, 0, 0, 0});
    tileIds2.push_back({0, 0, 0, 0, 0, 0, 0});

    ctorTimer.Reset();
    tilemap2_ = rpg::Tilemap{graphics_, tileset1_, tileIds2};
    std::cout << "map 2 time: " << ctorTimer << std::endl;

    ctorTimer.Reset();
    nge::FontPtr f = graphics_->LoadFont("resources/pokemon_pixel_font.ttf", 48);
    std::cout << "font time: " << ctorTimer << std::endl;

    ctorTimer.Reset();
    sprite1_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/SampleState/stewie.jpg", nge::Graphics::FULL_TEXTURE, {input_->GetMouseX(), input_->GetMouseY(), 100, 100}));
    std::cout << "sprite1_ time: " << ctorTimer << std::endl;
    sprite1_text_ = nge::Text{graphics_, f, nge::FontStyle::SOLID, "Mouse Movement", SDL_Point{input_->GetMouseX(), input_->GetMouseY()}};

    sprite2_text_ = nge::Text{graphics_, f, nge::FontStyle::SOLID, "Sprite Test", SDL_Point{50, 50}};
    ctorTimer.Reset();
    sprite2_ = nge::SpritePtr(new nge::Sprite(graphics_, "resources/SampleState/ibuki.png", nge::Graphics::FULL_TEXTURE, {0, sprite2_text_.GetY() + 30, 160, 206}));
    std::cout << "sprite2_ time: " << ctorTimer << std::endl;
    AlignHorizontal(sprite2_text_, *sprite2_);

    anim1_text_ = nge::Text{graphics_, f, nge::FontStyle::SOLID, "Animation Test 1", SDL_Point{300, 50}};
    anim1_ = std::make_unique<nge::AnimatedSprite>(
        graphics_, 
        "resources/SampleState/blaziken_anim_test.png", 
        nge::Graphics::FULL_TEXTURE, 
        SDL_Rect{0, anim1_text_.GetY() + 30, 100, 100}, 
        17, 
        2, 
        2
    );
    AlignHorizontal(anim1_text_, *anim1_);

    anim2_text_ = nge::Text{graphics_, f, nge::FontStyle::SOLID, "Animation Test 2", SDL_Point{900, 50}};
    anim2_ = std::make_unique<nge::AnimatedSprite>(graphics_, "resources/SampleState/kokichiwalk.png", nge::Graphics::FULL_TEXTURE, SDL_Rect{900, 80, 89, 90}, 2, -1, 15);
    AlignHorizontal(anim2_text_, *anim2_);

    butt1_text_ = nge::Text{graphics_, f, nge::FontStyle::SOLID, "Button Test", SDL_Point{600, 50}};
    nge::SpritePtr temp = std::make_unique<nge::Sprite>(graphics_, "resources/SampleState/hachigatsu.jpg", nge::Graphics::FULL_TEXTURE, SDL_Rect{600, 90, 250, 250});
    AlignHorizontal(butt1_text_, *temp);
    nge::SpritePtr tempHeld = std::make_unique<nge::Sprite>(graphics_, "resources/SampleState/hachigatsu_held.jpg", nge::Graphics::FULL_TEXTURE, SDL_Rect{600, 90, 250, 250});
    AlignHorizontal(butt1_text_, *tempHeld);
    butt1_ = std::make_shared<nge::Button>(input_, std::move(temp), SDL_Rect{600, 90, 250, 250});
    butt1_->SetHeldDrawable(std::move(tempHeld));
    butt1_->SetOnRelease([&](){
        if (std::shared_ptr<nge::StateManager> sm = states_.lock()) {
            sm->Advance(std::make_shared<State>(sm, graphics_));
        }
    });
    RegisterClickable(butt1_);


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
            //sm->Advance(std::make_shared<State>(sm, graphics_));
        }
    }
    if (input_->KeyPressed(SDL_SCANCODE_U)) {
        if (std::shared_ptr<nge::StateManager> sm = states_.lock()) {
            //sm->Advance(std::make_shared<SampleState>(sm, graphics_));
        }
    }
    if (input_->KeyPressed(SDL_SCANCODE_RETURN)) {
        anim1_->Reset();
    }
}

void SampleState::Draw() {
    double dt = draw_timer_.GetElapsedTime();
    sprite1_->SetX(input_->GetMouseX() - sprite1_->GetW() / 2);
    sprite1_->SetY(input_->GetMouseY() - sprite1_->GetH() / 2);
    sprite1_text_.SetX(input_->GetMouseX() - sprite1_text_.GetW() / 2);
    sprite1_text_.SetY(input_->GetMouseY() - 100);
    if (input_->KeyHeld(SDL_SCANCODE_Q)) {
        sprite2_->Rotate(-100.0 * dt);
    }
    if (input_->KeyHeld(SDL_SCANCODE_E)) {
        sprite2_->Rotate(100.0 * dt);
    }
    
    sprite1_->Draw();
    sprite1_text_.Draw();
    
    sprite2_->Draw();
    sprite2_text_.Draw();

    anim1_->Draw();
    anim1_text_.Draw();

    anim2_->Draw();
    anim2_text_.Draw();

    butt1_->Draw();
    butt1_text_.Draw();

    draw_timer_.Reset();

    
    SDL_Rect tempdst = {500, 500, 400, 400};
    SDL_QueryTexture(tilemap1_.GetMapTexture(), nullptr, nullptr, &tempdst.w, &tempdst.h);
    //SDL_RenderCopy(graphics_->GetRenderer(), target, nullptr, &tempdst);
    SDL_RenderCopy(graphics_->GetRenderer(), tilemap1_.GetMapTexture(), nullptr, &tempdst);
    SDL_RenderCopy(graphics_->GetRenderer(), tilemap2_.GetMapTexture(), nullptr, &tempdst);

    // tempdst = {100, 700, 32, 32};
    // SDL_RenderCopy(graphics_->GetRenderer(), tileset1_.GetT)

    // auto t2 = graphics_->LoadTexture("resources/SampleState/ibuki.png");
    
    // tilemap1_.Draw();
    // auto temp = tilemap1_.GetMapTexture();
    // SDL_SetRenderTarget(graphics_->GetRenderer(), temp);

    // graphics_->DrawTexture(tilemap1_.GetMapTexture(), nullptr, &tempdst);
}

SampleState::~SampleState() {
}