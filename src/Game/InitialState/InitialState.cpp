#include "InitialState.h"

#include <iostream>
#include "SDL2/SDL_ttf.h"

#include "Utility/SDL_RectExtensions.h"

InitialState::InitialState(nge::State init) : State(init) {
    title_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/title.png", nge::Graphics::FULL_TEXTURE, SDL_Rect{0, 0, 1200, 900});
    ibuki_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/ibuki.png", nge::Graphics::FULL_TEXTURE, SDL_Rect{50, 20, 640 / 4, 800 / 4});
    kaito_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/kaito.png", nge::Graphics::FULL_TEXTURE, SDL_Rect{900, 20, 600 / 4, 1080 / 4});
    
    nge::FontPtr f = graphics_->LoadFont("resources/pokemon_pixel_font.ttf", 72);
    SDL_Surface *s1 = TTF_RenderText_Solid(  f.get(), "solid", {0, 0, 0, 0});
    SDL_Surface *s2 = TTF_RenderText_Shaded( f.get(), "shaded", {0, 0, 0, 0}, {255, 255, 255, 255});
    SDL_Surface *s3 = TTF_RenderText_Blended(f.get(), "blended", {0, 0, 0, 0});
    solid_ =   SDL_CreateTextureFromSurface(graphics_->GetRenderer(), s1);
    shaded_ =  SDL_CreateTextureFromSurface(graphics_->GetRenderer(), s2);
    blended_ = SDL_CreateTextureFromSurface(graphics_->GetRenderer(), s3);

    solid_tex_ = graphics_->LoadText(f, nge::FontStyle::SOLID, "solid texture", {0, 0, 0, 0});
    shaded_tex_ = graphics_->LoadText(f, nge::FontStyle::SHADED, "solid texture", {0, 0, 0, 0}, {255, 255, 255, 255});
    blended_tex_ = graphics_->LoadText(f, nge::FontStyle::BLENDED, "solid texture", {0, 0, 0, 0});

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

    SDL_Rect src{0, 0, 0, 0};

    SDL_QueryTexture(solid_, nullptr, nullptr, &src.w, &src.h);
    SDL_Rect dst = {350, 350, src.w, src.h};
    graphics_->DrawTexture(solid_, &src, &dst);

    SDL_QueryTexture(shaded_, nullptr, nullptr, &src.w, &src.h);
    dst = {400, 400, src.w, src.h};
    graphics_->DrawTexture(shaded_, &src, &dst);

    SDL_QueryTexture(blended_, nullptr, nullptr, &src.w, &src.h);
    dst = {450, 450, src.w, src.h};
    graphics_->DrawTexture(blended_, &src, &dst);

    SDL_QueryTexture(solid_tex_.get(), nullptr, nullptr, &src.w, &src.h);
    dst = {500, 500, src.w, src.h};
    graphics_->DrawTexture(solid_tex_, &src, &dst);

    SDL_QueryTexture(shaded_tex_.get(), nullptr, nullptr, &src.w, &src.h);
    dst = {550, 550, src.w, src.h};
    graphics_->DrawTexture(shaded_tex_, &src, &dst);

    SDL_QueryTexture(blended_tex_.get(), nullptr, nullptr, &src.w, &src.h);
    dst = {600, 600, src.w, src.h};
    graphics_->DrawTexture(blended_tex_, &src, &dst);

}

InitialState::~InitialState() {
}