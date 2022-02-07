#ifndef _SAMPLESTATE_H
#define _SAMPLESTATE_H

#include <memory>

#include "Core/State.h"
#include "Core/Graphics.h"
#include "Core/StateManager.h"
#include "Components/Sprite.h"
#include "Components/AnimatedSprite.h"
#include "Timer.h"

class SampleState : public nge::State {
    public:
        SampleState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics);
        
        void Tick() override;
        void Draw() override;

        ~SampleState();

    private:
        nge::Timer draw_timer_;
        nge::SpritePtr sprite1_;
        nge::SpritePtr sprite2_;
        nge::AnimPtr anim1_;
};

#endif