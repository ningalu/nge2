#include "State.h"

#include <iostream>

#include "Utility/SDL_RectExtensions.h"
#include "InputInterfaces/Clickable.h"

namespace nge {
    State::State() {
    }

    State::State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics) {
        active_ = true;
        states_ = states;
        graphics_ = graphics;
        input_ = std::make_shared<Input>();
        default_sound_ = Audio::LoadSound("resources/default_sound.wav");
    }

    bool State::IsActive() {
        return active_;
    }

    void State::Tick() {
        if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            Quit();
        }
        if (input_->MouseClicked(Input::kLeft)) {
            Audio::PlaySound(default_sound_.get());
        }
    }

    void State::Draw() {
        graphics_->DrawTexture(graphics_->LoadTexture("resources/default_texture.png").get(), nullptr, nullptr);
    }

    void State::UpdatePreviousInput(){
        input_->UpdatePrevInput();
    }

    void State::UpdateCurrentInput(){
        input_->Update();
    }

    void State::RegisterClickable(std::shared_ptr<Clickable> clickable) {
        clickables_.push_back(clickable);
    }

    void State::ProcessClickables() {
        if (input_->MouseClicked(Input::kLeft)) {
            for (auto &c : clickables_) {
                if (PointInRect({input_->GetMouseX(), input_->GetMouseY()}, c->GetClickableRegion())) {
                    c->OnClick();
                }
            }
        }
        if (input_->MouseHeld(Input::kLeft)) {
            for (auto c : clickables_) {
                if (PointInRect({input_->GetMouseX(), input_->GetMouseY()}, c->GetClickableRegion())) {
                    c->OnHold();
                }
            }
        }
        if (input_->MouseReleased(Input::kLeft)) {
            for (auto c : clickables_) {
                if (PointInRect({input_->GetMouseX(), input_->GetMouseY()}, c->GetClickableRegion())) {
                    c->OnRelease();
                }
            }
        }
    }

    void State::Quit() {
        SDL_Event quit;
        quit.type = SDL_QUIT;
        SDL_PushEvent(&quit);
    }

    State::~State() {
    }

}