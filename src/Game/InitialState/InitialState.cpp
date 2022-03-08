#include "InitialState.h"

#include <iostream>
#include "SDL2/SDL_ttf.h"

#include "Core/Utility/SDL_RectExtensions.h"
#include "Game/SampleState.h"
#include "Game/OverworldState/OverworldState.h"

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
    solid_text_->SetX(150);
    solid_text_->SetAngle(30.0);

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
    SDL_Rect startButtonTextDst = startButtonText->GetDestRect();
    start_button_ = std::make_shared<nge::Button>(
        input_, 
        std::move(startButtonText), 
        startButtonTextDst
    );
    start_button_->SetHeldDrawable(std::move(startButtonHeldText));

    start_button_->SetOnRelease([&](){
        Advance<SampleState>();
    });

    nge::TextPtr rpgText = std::make_unique<nge::Text>(
        graphics_,  
        f,
        nge::FontStyle::SOLID,
        "RPG",
        SDL_Point{450, 500}
    );
    nge::TextPtr rpgTextHover = std::make_unique<nge::Text>(
        graphics_,  
        f,
        nge::FontStyle::SOLID,
        "RPG",
        SDL_Point{rpgText->GetX(), rpgText->GetY()},
        SDL_Color{0, 0, 0, 120}
    );
    nge::TextPtr rpgTextHeld = std::make_unique<nge::Text>(
        graphics_,  
        f,
        nge::FontStyle::SOLID,
        "RPG",
        SDL_Point{rpgText->GetX()+5, rpgText->GetY()+5},
        SDL_Color{0, 0, 0, 120}
    );
    SDL_Rect rpgTextSrc = rpgText->GetDestRect();
    rpg_button_ = std::make_shared<nge::Button>(
        input_,
        std::move(rpgText),
        rpgTextSrc
    );
    rpg_button_->SetHoverDrawable(std::move(rpgTextHover));
    rpg_button_->SetHeldDrawable(std::move(rpgTextHeld));

    rpg_button_->SetOnRelease([&](){
        Advance<rpg::OverworldState>();
    });

    RegisterClickable(start_button_);
    RegisterClickable(rpg_button_);

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
    rpg_button_->Draw();

}

InitialState::~InitialState() {
}