#include "InitialState.h"

#include <iostream>
#include "SDL2/SDL_ttf.h"

#include "Utility/SDL_RectExtensions.h"

InitialState::InitialState(nge::State init) : State(init) {
    title_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/title.png", nge::Graphics::FULL_TEXTURE, SDL_Rect{0, 0, 1200, 900});
    ibuki_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/ibuki.png", nge::Graphics::FULL_TEXTURE, SDL_Rect{50, 20, 640 / 4, 800 / 4});
    kaito_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/kaito.png", nge::Graphics::FULL_TEXTURE, SDL_Rect{900, 20, 600 / 4, 1080 / 4});
    
    nge::FontPtr f = graphics_->LoadFont("resources/pokemon_pixel_font.ttf", 72);

    solid_text_ = std::make_unique<nge::Text>(
        graphics_, 
        f, 
        nge::FontStyle::SOLID, 
        "solid text", 
        SDL_Point{400, 400}, 
        SDL_Color{0, 0, 0, 0}
    );
    shaded_text_ = std::make_unique<nge::Text>(
        graphics_, 
        f, 
        nge::FontStyle::SOLID, 
        "shaded text", 
        SDL_Point{450, 450}, 
        SDL_Color{0, 0, 0, 0}
    );
    blended_text_ = std::make_unique<nge::Text>(
        graphics_, 
        f, 
        nge::FontStyle::SOLID, 
        "blended text", 
        SDL_Point{500, 500}, 
        SDL_Color{0, 0, 0, 0}
    );

    RegisterKeyEvent(
        SDL_SCANCODE_ESCAPE, 
        nge::InputState::PRESSED | nge::InputState::PRESSED, 
        [&](){
            Quit();
        }
    );

    draw_timer_.Start();
}

void InitialState::Tick() {
}

void InitialState::Draw() {
    title_->Draw();
    ibuki_->Draw();
    kaito_->Draw();

    solid_text_->Draw();
    shaded_text_->Draw();
    blended_text_->Draw();

}

InitialState::~InitialState() {
}