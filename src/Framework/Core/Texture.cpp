#include "Texture.h"

namespace nge {
    Texture::Texture(SDL_Texture* texture) : texture_(texture) {
    }

    SDL_Texture* const Texture::get() const {
        return texture_;
    }

    Texture::~Texture() {
        SDL_DestroyTexture(texture_);
    }
}