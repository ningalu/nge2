#include "Switch.h"

#include "Core/Utility/SDL_RectExtensions.h"

namespace nge {
    Switch::Switch(
        std::shared_ptr<Input> input, 
        std::unique_ptr<Drawable> onDrawable, 
        std::unique_ptr<Drawable> offDrawable,
        SDL_Rect clickableRegion,
        SwitchState state,
        bool clickEnabled
    ) : on_drawable_(std::move(onDrawable)), off_drawable_(std::move(offDrawable)) {
        input_ = input;
        clickable_region_ = clickableRegion;
        on_toggle_on_ = [](){return;};
        on_toggle_off_ = [](){return;};
        state_ = state;
        click_enabled_ = clickEnabled;
    }

    // Drawable Interface
    void Switch::Draw() {
        state_ == SwitchState::ON ? on_drawable_->Draw() : off_drawable_->Draw();
    }

    bool Switch::Overlaps(SDL_Rect area) {
        return HasIntersect(area, clickable_region_);
    }

    // Clickable Interface
    void Switch::OnClick() {
        if (click_enabled_) {
            Toggle();
        }
    }

    void Switch::OnHold() {

    }

    void Switch::OnRelease() {

    }

    const SDL_Rect& Switch::GetClickableRegion() const {
        return clickable_region_;
    }

    void Switch::SetOnToggleOn(std::function<void(void)> onToggleOn) {
        on_toggle_on_ = onToggleOn;
    }

    void Switch::SetOnToggleOff(std::function<void(void)> onToggleOff) {
        on_toggle_off_ = onToggleOff;
    }
    
    void Switch::Toggle(bool suppress) {
        switch(state_) {
            case SwitchState::ON:
                state_ = SwitchState::OFF;
                break;
            case SwitchState::OFF:
                state_ = SwitchState::ON;
                break;
        }
        if (!suppress) {
            state_ == SwitchState::ON ? on_toggle_on_() : on_toggle_off_();
        }
    }

    void Switch::SetState(SwitchState state, bool suppress) {
        switch(state) {
            case SwitchState::ON:
                state_ = SwitchState::ON;
                break;
            case SwitchState::OFF:
                state_ = SwitchState::OFF;
                break;
        }
        if (!suppress) {
            state_ == SwitchState::ON ? on_toggle_on_() : on_toggle_off_();
        }
    }

    void Switch::Enable() {
        click_enabled_ = true;
    }

    void Switch::Disable() {
        click_enabled_ = false;
    }

    void Switch::SetEnabled(bool enable) {
        click_enabled_ = enable;
    }
    
}