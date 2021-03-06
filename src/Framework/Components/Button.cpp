#include "Button.h"

#include <iostream>

#include "Core/Utility/SDL_RectExtensions.h"

namespace nge {
Button::Button() {}
Button::Button(std::shared_ptr<Input> input,
               std::unique_ptr<Drawable> defaultDrawable,
               SDL_Rect clickableRegion)
    : default_drawable_(std::move(defaultDrawable)), input_(input) {
  state_ = ButtonState::NONE;

  clickable_region_ = clickableRegion;

  held_drawable_ = nullptr;
  SetOnClick([]() { return; });
  SetOnHold([]() { return; });
  SetOnRelease([]() { return; });
}

const SDL_Rect &Button::GetClickableRegion() const { return clickable_region_; }

bool Button::Overlaps(SDL_Rect area) { return true; }

void Button::AlignHorizontal(int x) {}

void Button::AlignVertical(int y) {}

void Button::OnClick() {
  state_ = ButtonState::HELD;
  on_click_();
}

void Button::OnHold() {
  if (state_ == ButtonState::HELD) {
    on_hold_();
  }
}

void Button::OnRelease() {
  if (state_ == ButtonState::HELD) {
    state_ = ButtonState::NONE;
    on_release_();
  }
}

void Button::Draw() {
  bool hovering = PointInRect(input_->GetMousePoint(), clickable_region_);
  if (!hovering) {
    state_ = ButtonState::NONE;
  }
  if ((state_ == ButtonState::HELD) && (held_drawable_ != nullptr)) {
    held_drawable_->Draw();
  } else if ((hovering) && (hover_drawable_ != nullptr)) {
    hover_drawable_->Draw();
  } else {
    default_drawable_->Draw();
  }
}

int Button::GetX() { return clickable_region_.x; }

int Button::GetY() { return clickable_region_.y; }

int Button::GetW() { return clickable_region_.w; }

int Button::GetH() { return clickable_region_.h; }

SDL_Rect Button::GetDestRect() { return clickable_region_; }

void Button::SetOnClick(std::function<void(void)> onClick) {
  on_click_ = onClick;
}

void Button::SetOnHold(std::function<void(void)> onHold) { on_hold_ = onHold; }

void Button::SetOnRelease(std::function<void(void)> onRelease) {
  on_release_ = onRelease;
}

void Button::SetHeldDrawable(std::unique_ptr<Drawable> heldDrawable) {
  held_drawable_ = std::move(heldDrawable);
}

void Button::SetHoverDrawable(std::unique_ptr<Drawable> hoverDrawable) {
  hover_drawable_ = std::move(hoverDrawable);
}

bool Button::MouseOver(int mouseX, int mouseY) {
  return PointInRect({mouseX, mouseY}, clickable_region_);
}

Button::~Button() {}
} // namespace nge