#include "SDL_EventExtensions.h"

std::ostream& operator<<(std::ostream& os, const SDL_Event& event) {
    os << event.type;
    return os;
}