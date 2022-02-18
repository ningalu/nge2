#ifndef CORE_INPUTINTERFACES_CLICKABLE_H
#define CORE_INPUTINTERFACES_CLICKABLE_H

#include "SDL2/SDL.h"

namespace nge {
    // Should the Clickable or its container control whether a mouse click is valid to trigger the Clickable action?
    class Clickable {
        public:
            virtual void OnClick() = 0;
            virtual void OnHold() = 0;
            virtual void OnRelease() = 0;
            virtual void EnableClick() = 0;
            virtual void DisableClick() = 0;
            virtual const SDL_Rect& GetClickableRegion() const = 0;
    };
}

#endif