#include "Button.h"

#include <iostream>

namespace nge {
    Button::Button(std::shared_ptr<Input> input, std::unique_ptr<Drawable> defaultDraw, SDL_Rect clickableRegion) : default_draw_(std::move(defaultDraw)) {
        enabled_ = true;
        clickable_region_ = clickableRegion;
    }

    const SDL_Rect& Button::GetClickableRegion() const {
        return clickable_region_;
    }

    void Button::OnClick() {
        if (enabled_) {
            on_click_();
        }
    }

    void Button::OnHold() {
        if (enabled_) {
            on_hold_();
        }
    }

    void Button::OnRelease() {
        if (enabled_) {
            on_release_();
        }
    }

    void Button::EnableClick() {
        enabled_ = true;
    }

    void Button::DisableClick() {
        enabled_ = false;
    }

    void Button::Draw() {
        default_draw_->Draw();
    }
    
    int Button::GetX() {
        return clickable_region_.x;
    }
    
    int Button::GetY() {
        return clickable_region_.y;
    }
    
    void Button::SetOnClick(std::function<void(void)> onClick) {
        on_click_ = onClick;
    }

    void Button::SetOnHold(std::function<void(void)> onHold) {
        on_hold_ = onHold;
    }

    void Button::SetOnRelease(std::function<void(void)> onRelease) {
        on_release_ = onRelease;
    }

    Button::~Button() {

    }
}