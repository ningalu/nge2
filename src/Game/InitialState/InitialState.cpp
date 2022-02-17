#include "InitialState.h"

#include <iostream>

#include "Utility/SDL_RectExtensions.h"

InitialState::InitialState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics) : State(states, graphics) {
    title_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/title.png", nge::Sprite::FULL_TEXTURE, SDL_Rect{0, 0, 1200, 900});
    ibuki_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/ibuki.png", nge::Sprite::FULL_TEXTURE, SDL_Rect{50, 20, 640 / 4, 800 / 4});
    kaito_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/kaito.png", nge::Sprite::FULL_TEXTURE, SDL_Rect{900, 20, 600 / 4, 1080 / 4});
    
    draw_timer_.Start();
}

void InitialState::Tick() {
}

void InitialState::Draw() {
    title_->Draw();
    ibuki_->Draw();
    kaito_->Draw();

}

InitialState::~InitialState() {
}