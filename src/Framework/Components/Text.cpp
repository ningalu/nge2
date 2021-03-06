#include "Text.h"

#include "Core/Utility/SDL_PointExtensions.h"

namespace nge {
    Text::Text(
        std::shared_ptr<Graphics> graphics, 
        FontPtr font, 
        FontStyle style,
        const std::string& text, 
        SDL_Point dst, 
        SDL_Color colour,
        SDL_Color bg,
        double angle,
        SDL_Point rotationCentre,
        SDL_RendererFlip flip
    ) : graphics_(graphics) {

        texture_ = graphics_->LoadText(font, style, text, colour, bg);

        src_ = {0, 0, 0, 0};
        SDL_QueryTexture(texture_.get(), nullptr, nullptr, &src_.w, &src_.h);

        dst_ = {dst.x, dst.y, src_.w, src_.h};

        angle_ = angle;

        if (rotationCentre == Graphics::ROTATION_CENTRE) {
            rotation_centre_.x = dst_.w / 2;
            rotation_centre_.y = dst_.h / 2;
        } else {
            rotation_centre_ = rotationCentre;
        }

        flip_ = flip;
    
    }

    void Text::Draw() {
        graphics_->DrawTexture(texture_, &src_, &dst_, angle_, &rotation_centre_, flip_);
    }
    
    Text::~Text() {
        
    }
}