#include "State.h"

#include <iostream>
#include <algorithm>

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
        if (input_->MouseClicked(MouseButton::LEFT)) {
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
        if (input_->MouseClicked(MouseButton::LEFT)) {
            for (auto &c : clickables_) {
                if (PointInRect({input_->GetMouseX(), input_->GetMouseY()}, c->GetClickableRegion())) {
                    c->OnClick();
                }
            }
        }
        if (input_->MouseHeld(MouseButton::LEFT)) {
            for (auto c : clickables_) {
                if (PointInRect({input_->GetMouseX(), input_->GetMouseY()}, c->GetClickableRegion())) {
                    c->OnHold();
                }
            }
        }
        if (input_->MouseReleased(MouseButton::LEFT)) {
            for (auto c : clickables_) {
                if (PointInRect({input_->GetMouseX(), input_->GetMouseY()}, c->GetClickableRegion())) {
                    c->OnRelease();
                }
            }
        }
    }

    void State::RegisterKeyPressedEvent(SDL_Scancode key, std::function<void(void)> event) {
        auto it = std::find_if(
            keydown_events_.begin(), 
            keydown_events_.end(), 
            [&](auto it){
                return it.first == key;
            }
        );
        if (it == keydown_events_.end()) {
            std::cout << "not found" << std::endl;
            keydown_events_.push_back({key, event});
        } else {
            std::cout << "found, replaced" << std::endl;
            it->second = event;
        }
    }

    void State::ProcessKeyboardEvents() {
        for (auto e : keydown_events_) {
            if (input_->KeyPressed(e.first)) {
                e.second();
            }
        }
    }

    void State::ProcessInputs() {
        ProcessClickables();
        ProcessKeyboardEvents();
    }

    void State::Quit() {
        SDL_Event quit;
        quit.type = SDL_QUIT;
        SDL_PushEvent(&quit);
    }

    State::~State() {
    }

}