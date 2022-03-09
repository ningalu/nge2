#include "Switch.h"

#include "Core/Utility/SDL_RectExtensions.h"

namespace nge {
    Switch::Switch(
        std::shared_ptr<Input> input, 
        std::unique_ptr<Drawable> onDrawable, 
        std::unique_ptr<Drawable> offDrawable,
        SDL_Rect clickableRegion
    ) : on_drawable_(std::move(onDrawable)), off_drawable_(std::move(offDrawable)) {
        input_ = input;
        clickable_region_ = clickableRegion;
        on_toggle_on_ = [](){return;};
        on_toggle_off_ = [](){return;};
    }

    // Drawable Interface
    void Switch::Draw() {
        on_ ? on_drawable_->Draw() : off_drawable_->Draw();
    }

    bool Switch::Overlaps(SDL_Rect area) {
        return HasIntersect(area, clickable_region_);
    }

    // Clickable Interface
    void Switch::OnClick() {
        Toggle();
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
        on_ = !on_;
        if (!suppress) {
            on_ ? on_toggle_on_() : on_toggle_off_();
        }
    }

}