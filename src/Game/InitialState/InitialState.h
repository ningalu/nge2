#ifndef _GAME_INITIALSTATE_INITIALSTATE_H
#define _GAME_INITIALSTATE_INITIALSTATE_H

#include <memory>

#include "Core/State.hpp"
#include "Core/Graphics.h"
#include "Core/StateManager.h"
#include "Components/Sprite.h"
#include "Components/Button.h"
#include "Components/AnimatedSprite.h"
#include "Components/Text.h"
#include "Core/Timer.h"
#include "Components/Button.h"

class InitialState : public nge::State {
    public:
        InitialState(nge::State init);
        
        void Tick() override;
        void Draw() override;

        ~InitialState();

    private:
        nge::Timer draw_timer_;

        nge::SpritePtr title_;
        nge::SpritePtr ibuki_;
        nge::SpritePtr kaito_;
        
        nge::TextPtr solid_text_;
        nge::TextPtr shaded_text_;
        nge::TextPtr blended_text_;

        nge::ButtonPtr start_button_;
        nge::ButtonPtr rpg_button_;
        nge::ButtonPtr info_button_;
        nge::ButtonPtr quit_button_;

        SDL_Texture *solid_, *shaded_, *blended_;
};

#endif