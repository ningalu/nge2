#ifndef CORE_INPUTINTERFACES_CLICKABLE_H
#define CORE_INPUTINTERFACES_CLICKABLE_H

#include "SDL2/SDL.h"

namespace nge {
    // Should the Clickable or its container control whether a mouse click is valid to trigger the Clickable action?
    class Clickable {
        public:
            void OnClick();
            void OnHold();
            void OnRelease();
            void EnableClick();
            void DisableClick();
            const SDL_Rect& GetClickableRegion() const;
    };
}

#endif