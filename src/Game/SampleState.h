#ifndef _GAME_SAMPLESTATE_H
#define _GAME_SAMPLESTATE_H

#include <memory>

#include "Core/State.hpp"
#include "Core/Graphics.h"
#include "Core/StateManager.h"
#include "Components/Sprite.h"
#include "Components/AnimatedSprite.h"
#include "Core/Timer.h"
#include "Components/Button.h"
#include "Components/Text.h"
#include "OverworldState/Tileset.h"
#include "OverworldState/Tilemap.h"

class SampleState : public nge::State {
    public:
        SampleState(nge::State init);
        
        void Tick() override;
        void Draw() override;

        ~SampleState();

    private:
        nge::Timer draw_timer_;
        
        nge::SpritePtr sprite1_;
        nge::Text sprite1_text_;

        nge::SpritePtr sprite2_;
        nge::Text sprite2_text_;

        nge::AnimPtr anim1_;
        nge::Text anim1_text_;

        nge::AnimPtr anim2_;
        nge::Text anim2_text_;

        nge::AnimPtr anim3_;
        nge::Text anim3_text_;

        nge::ButtonPtr butt1_;
        nge::Text butt1_text_;

        nge::Button butt2_;

        std::shared_ptr<rpg::Tileset> tileset1_;
        rpg::Tilemap tilemap1_, tilemap2_;
        SDL_Rect cam_src_, cam_dst_;
};

#endif