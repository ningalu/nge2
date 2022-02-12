#ifndef _BUTTON_H
#define _BUTTON_H

#include "Sprite.h"

#include <memory>
#include <functional>

#include "Input.h"
#include "InputInterfaces/Clickable.h"
#include "GraphicsInterfaces/Drawable.h"

namespace nge {
    class Button : public Clickable, public Drawable {
        public:
            Button(std::shared_ptr<Input> input, std::unique_ptr<Drawable> defaultDraw, SDL_Rect clickableRegion);

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

            void SetOnClick(std::function<void(void)> onClick);
            void SetOnHold(std::function<void(void)> onHold);
            void SetOnRelease(std::function<void(void)> onRelease);

            ~Button();

        protected:
            bool enabled_;
            SDL_Rect clickable_region_;
            std::unique_ptr<Drawable> default_draw_;
            std::function<void(void)> on_click_, on_hold_, on_release_;
    };

    using ButtonPtr = std::unique_ptr<Button>;
}

#endif