#include "MiningState.h"

#include <vector>

#include "Core/Timer.h"
MiningState::MiningState(nge::State state) : nge::State(state) {
    graphics_->SetWindowSize(520, 384);
    cursor_ = nge::AnimatedSprite{
        graphics_, 
        "resources/MiningState/hammer_sprite.png", 
        nge::Graphics::FULL_TEXTURE,
        {input_->GetMouseX(), input_->GetMouseY(), 72, 64},
        4,
        1,
        5
    };
    background_ = nge::Sprite{
        graphics_,
        "resources/MiningState/background.png",
        nge::Graphics::FULL_TEXTURE,
        {0, 0, 520, 384}
    };

    RegisterKeyEvent(SDL_SCANCODE_ESCAPE, nge::InputState::PRESSED, [&](){
        Return();
    });
}
void MiningState::Draw() {
    cursor_.AlignHorizontal(input_->GetMouseX());
    cursor_.AlignVertical(input_->GetMouseY());
    background_.Draw();
    cursor_.Draw();
}

void MiningState::Tick() {
    if (input_->MouseClicked(nge::MouseButton::LEFT)) {
        cursor_.Reset();
    }
}
