#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "SDL2/SDL.h"

// Wrap SDL_Texture instead of using unique_ptr to avoid initialiser list construction every time its used
namespace nge {
    class Texture {
        public:
            Texture(SDL_Texture* texture);
            
            SDL_Texture* const get() const;

            ~Texture();
        private:
            SDL_Texture *texture_;

    };
}

#endif