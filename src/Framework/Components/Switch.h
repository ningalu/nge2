#ifndef _FRAMEWORK_COMPONENTS_SWITCH_H
#define _FRAMEWORK_COMPONENTS_SWITCH_H

#include <memory>
#include <functional>

#include "SDL2/SDL.h"

#include "Core/Input.h"
#include "Core/Interfaces/Clickable.h"
#include "Core/Interfaces/Drawable.h"

namespace nge {
    enum class SwitchState {
        ON,
        OFF
    };

    class Switch : public Drawable, public Clickable {
        public:
            Switch() = default;
            Switch(
                std::shared_ptr<Input> input, 
                std::unique_ptr<Drawable> onDrawable, 
                std::unique_ptr<Drawable> offDrawable,
                SDL_Rect clickableRegion,
                SwitchState state = SwitchState::OFF,
                bool clickEnabled = true
            );

            // Drawable Interface
            void Draw();
            bool Overlaps(SDL_Rect area);

            // Clickable Interface
            void OnClick();
            void OnHold();
            void OnRelease();
            const SDL_Rect& GetClickableRegion() const;

            void SetOnToggleOn(std::function<void(void)> onToggleOn);
            void SetOnToggleOff(std::function<void(void)> onToggleOff);

            void Toggle(bool suppress = false);
            void SetState(SwitchState state, bool suppress = true);

            void Enable();
            void Disable();
            void SetEnabled(bool enable);
        
        protected:
            SwitchState state_;
            bool click_enabled_;
            SDL_Rect clickable_region_;
            std::shared_ptr<Input> input_;
            std::function<void(void)> on_toggle_on_, on_toggle_off_;
            std::unique_ptr<Drawable> on_drawable_, off_drawable_;
    
    };
    using SwitchPtr = std::shared_ptr<Switch>;
}

#endif