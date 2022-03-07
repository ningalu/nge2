#ifndef _GAME_MININGSTATE_MININGSTATE_H
#define _GAME_MININGSTATE_MININGSTATE_H

#include "Core/State.hpp"

#include <array>

#include "Components/AnimatedSprite.h"

class MiningState : public nge::State {
    
    using MiningLayer = std::array<std::array<int, 13>, 10>;
    using SpriteLayer = std::array<std::array<nge::Sprite, 13>, 10>;
    
    enum class Tool {
        HAMMER,
        PICKAXE
    };

    public:
        MiningState(nge::State state);
        void Draw();
        void Tick();
        ~MiningState() = default;

    protected:
        std::array<MiningLayer, 4> layers_;
        std::array<SpriteLayer, 4> layer_sprites_;
        nge::AnimatedSprite cursor_;
        nge::Sprite background_;
        const SDL_Point MINING_TILE_START_POINT = {0, 64};
        std::vector<std::vector<nge::TexturePtr>> layer_textures_;

};


#endif