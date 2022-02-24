#include "InitialState.h"

#include <iostream>
#include "SDL2/SDL_ttf.h"

#include "Utility/SDL_RectExtensions.h"
#include "Game/SampleState.h"

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
        SDL_Point{100, 800}, 
        SDL_Color{0, 0, 0, 0}
    );
    shaded_text_ = std::make_unique<nge::Text>(
        graphics_, 
        f, 
        nge::FontStyle::SHADED, 
        "shaded text", 
        SDL_Point{450, 800}, 
        SDL_Color{0, 0, 0, 0},
        SDL_Color{255, 255, 255, 0}
    );
    blended_text_ = std::make_unique<nge::Text>(
        graphics_, 
        f, 
        nge::FontStyle::BLENDED, 
        "blended text", 
        SDL_Point{800, 800}, 
        SDL_Color{0, 0, 0, 0}
    );

    nge::TextPtr startButtonText = std::make_unique<nge::Text>(
        graphics_,
        f,
        nge::FontStyle::SOLID,
        "Start",
        SDL_Point{150, 500},
        SDL_Color{0, 0, 0, 0}
    );
    nge::TextPtr startButtonHeldText = std::make_unique<nge::Text>(
        graphics_,
        f,
        nge::FontStyle::SOLID,
        "Start",
        SDL_Point{150, 500},
        SDL_Color{0, 0, 0, 128}
    );

    start_button_ = std::make_shared<nge::Button>(
        input_, 
        std::move(startButtonText), 
        SDL_Rect{150, 500, 200, 100}
    );
    start_button_->SetHeldDrawable(std::move(startButtonHeldText));

    start_button_->SetOnRelease([&](){
        Advance<SampleState>();
        // if (std::shared_ptr<nge::StateManager> sm = states_.lock()) {
        //     nge::State s(sm, graphics_);
        //     auto n = std::make_shared<SampleState>(s);
        //     Advance(n);
        // }
    });

    RegisterClickable(start_button_);

    RegisterKeyEvent(
        SDL_SCANCODE_ESCAPE, 
        nge::InputState::PRESSED,
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

    start_button_->Draw();

}

InitialState::~InitialState() {
}