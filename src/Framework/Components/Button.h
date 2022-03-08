#ifndef _COMPONENTS_BUTTON_H
#define _COMPONENTS_BUTTON_H

#include "Sprite.h"

#include <memory>
#include <functional>

#include "Core/Input.h"
#include "Core/Interfaces/Clickable.h"
#include "Core/Interfaces/Drawable.h"

namespace nge {
    enum class ButtonState {
        NONE,
        HOVER,
        HELD
    };

    class Button : public Clickable, public Drawable {
        public:
            Button();
            Button(std::shared_ptr<Input> input, std::unique_ptr<Drawable> defaultDrawable, SDL_Rect clickableRegion);

            // Clickable Interface
            void OnClick();
            void OnHold();
            void OnRelease();
            void EnableClick();
            void DisableClick();
            const SDL_Rect& GetClickableRegion() const;

            // Drawable Interface
            void Draw();
            int GetX();
            int GetY();
            int GetW();
            int GetH();
            SDL_Rect GetDestRect();

            bool Overlaps(SDL_Rect area);
            void AlignHorizontal(int x);
            void AlignVertical(int y);

            void SetButtonState(ButtonState state);

            void SetOnClick(std::function<void(void)> onClick);
            void SetOnHold(std::function<void(void)> onHold);
            void SetOnRelease(std::function<void(void)> onRelease);

            void SetHeldDrawable(std::unique_ptr<Drawable> heldDrawable);

            bool MouseOver(int mouseX, int mouseY);

            ~Button();

        protected:
            std::shared_ptr<Input> input_;
            bool enabled_;
            bool held_;
            ButtonState state_;
            SDL_Rect clickable_region_;
            std::unique_ptr<Drawable> default_drawable_, hover_drawable_, held_drawable_;
            std::function<void(void)> on_click_, on_hold_, on_release_;
    };

    using ButtonPtr = std::shared_ptr<Button>;
}

#endif