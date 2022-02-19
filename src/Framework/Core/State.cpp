#include "State.h"

#include <iostream>
#include <algorithm>
#include <cmath>

#include "Utility/SDL_RectExtensions.h"
#include "Interfaces/Clickable.h"

namespace nge {
    State::State() {
    }

    State::State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics) : states_(states), graphics_(graphics) {
        base_path_ = SDL_GetBasePath();
        active_ = true;
        quit_ = false;
        input_ = std::make_shared<Input>();
    }

    bool State::IsActive() const {
        return active_;
    }

    bool State::GameEnded() const {
        return quit_;
    }

    void State::ProcessInput() {
        input_->UpdatePrevInput();
        while (SDL_PollEvent(&event_buffer_)) {
            switch (event_buffer_.type) {
                case SDL_QUIT:
                    std::cout << "SDL_QUIT" << std::endl;
                    quit_ = true;
                    return;
            }  
        }
        input_->Update();
        
        ProcessClickables();
        ProcessKeyboardEvents();
    }

    void State::Tick() {
        if (input_->KeyPressed(SDL_SCANCODE_ESCAPE)) {
            Return();
        }
        if (input_->MouseClicked(MouseButton::LEFT)) {
            Audio::PlaySound(Audio::LoadSound("resources/State/default_sound.wav").get());
        }
    }

    void State::Draw() {
        graphics_->DrawTexture(graphics_->LoadTexture("resources/State/default_texture.png").get(), nullptr, nullptr);
    }

    void State::RegisterClickable(std::shared_ptr<Clickable> clickable) {
        clickables_.push_back(clickable);
    }

    void State::RegisterKeyEvent(SDL_Scancode key, int flags, std::function<void(void)> event) {
        if (flags & (1 << 0)) {
            RegisterKeyEvent(key, event, keypressed_events_);
        }
        if (flags & (1 << 1)) {
            RegisterKeyEvent(key, event, keyheld_events_);
        }
        if (flags & (1 << 2)) {
            RegisterKeyEvent(key, event, keyreleased_events_);
        }
    }

    void State::RegisterKeyEvent(SDL_Scancode key, InputState flag, std::function<void(void)> event) {
        RegisterKeyEvent(key, static_cast<int>(flag), event);
    }

    void State::RegisterKeyEvent(SDL_Scancode key, std::function<void(void)> event, std::vector<std::pair<SDL_Scancode, std::function<void(void)> > >& eventList) {
        auto it = std::find_if(
            eventList.begin(), 
            eventList.end(), 
            [&](auto it){
                return it.first == key;
            }
        );
        if (it == eventList.end()) {
            eventList.push_back({key, event});
        } else {
            it->second = event;
        }
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

    void State::ProcessKeyboardEvents() {
        for (auto e : keypressed_events_) {
            if (input_->KeyPressed(e.first)) {
                e.second();
            }
        }
        for (auto e : keyheld_events_) {
            if (input_->KeyHeld(e.first)) {
                e.second();
            }
        }
        for (auto e : keyreleased_events_) {
            if (input_->KeyReleased(e.first)) {
                e.second();
            }
        }
    }

    void State::Return() {
        active_ = false;
    }

    void State::Quit() {
        SDL_Event quit;
        quit.type = SDL_QUIT;
        SDL_PushEvent(&quit);
    }

    State::~State() {
    }

}