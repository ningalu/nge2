#ifndef _GAME_MININGSTATE_MININGSTATE_H
#define _GAME_MININGSTATE_MININGSTATE_H

#include "Core/State.hpp"

#include <array>

#include "Components/AnimatedSprite.h"
#include "Components/Button.h"

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
        const SDL_Point MINING_TILE_START_POINT = {0, 64};
        const SDL_Point HAMMER_BUTTON = {217 * 2, 55 * 2};
        const SDL_Point PICKAXE_BUTTON = {217 * 2, 127 * 2};
        Tool tool_;

        std::array<MiningLayer, 4> layers_;
        std::array<SpriteLayer, 4> layer_sprites_;
        std::vector<std::vector<nge::TexturePtr>> layer_textures_;

        nge::AnimatedSprite cursor_;
        nge::Sprite background_;
        nge::ButtonPtr hammer_button_, pickaxe_button_;
        
        void Hit(SDL_Point point);
        SDL_Point GetMousePosInMine(int x, int y);
        bool PosIsValid(SDL_Point mousePos);
};


#endif