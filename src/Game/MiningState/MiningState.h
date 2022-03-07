#ifndef _GAME_MININGSTATE_MININGSTATE_H
#define _GAME_MININGSTATE_MININGSTATE_H

#include "Core/State.hpp"

#include <array>

#include "Components/AnimatedSprite.h"

class MiningState : public nge::State {
    public:
        MiningState(nge::State state);
        void Draw();
        void Tick();
        ~MiningState() = default;

    protected:
        std::array<std::array<int, 10>, 13> layer;
        nge::AnimatedSprite cursor_;
        nge::Sprite background_;

};


#endif