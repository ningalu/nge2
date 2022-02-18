#include "InitialState.h"

#include <iostream>
#include "SDL2/SDL_ttf.h"

#include "Utility/SDL_RectExtensions.h"

InitialState::InitialState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics) : State(states, graphics) {
    title_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/title.png", nge::Sprite::FULL_TEXTURE, SDL_Rect{0, 0, 1200, 900});
    ibuki_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/ibuki.png", nge::Sprite::FULL_TEXTURE, SDL_Rect{50, 20, 640 / 4, 800 / 4});
    kaito_ = std::make_unique<nge::Sprite>(graphics_, "resources/InitialState/kaito.png", nge::Sprite::FULL_TEXTURE, SDL_Rect{900, 20, 600 / 4, 1080 / 4});
    
    TTF_Font *f = TTF_OpenFont("resources/pokemon_pixel_font.ttf", 72);
    SDL_Surface *s1 = TTF_RenderText_Solid(f, "solid", {0, 0, 0, 0});
    SDL_Surface *s2 = TTF_RenderText_Shaded(f, "shaded", {0, 0, 0, 0}, {255, 255, 255, 255});
    SDL_Surface *s3 = TTF_RenderText_Blended(f, "blended", {0, 0, 0, 0});
    solid_ = SDL_CreateTextureFromSurface(graphics_->GetRenderer(), s1);
    shaded_ = SDL_CreateTextureFromSurface(graphics_->GetRenderer(), s2);
    blended_ = SDL_CreateTextureFromSurface(graphics_->GetRenderer(), s3);

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
    SDL_Rect dst = {600, 600, src.w, src.h};
    graphics_->DrawTexture(solid_, &src, &dst);
    SDL_QueryTexture(shaded_, nullptr, nullptr, &src.w, &src.h);
    dst = {650, 650, src.w, src.h};
    graphics_->DrawTexture(shaded_, &src, &dst);
    SDL_QueryTexture(blended_, nullptr, nullptr, &src.w, &src.h);
    dst = {700, 700, src.w, src.h};
    graphics_->DrawTexture(blended_, &src, &dst);


}

InitialState::~InitialState() {
}