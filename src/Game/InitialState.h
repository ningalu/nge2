#ifndef _INITIALSTATE_H
#define _INITIALSTATE_H

#include <memory>

#include "Core/State.h"
#include "Core/Graphics.h"
#include "Core/StateManager.h"
#include "Components/Sprite.h"

class InitialState : public nge::State {
    public:
        InitialState(std::shared_ptr<nge::StateManager> states, std::shared_ptr<nge::Graphics> graphics);
        
        void Tick() override;
        void Draw() override;

        ~InitialState();

    private:
        nge::SpritePtr sprite_;
};

#endif