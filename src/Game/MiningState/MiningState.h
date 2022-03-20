#ifndef _GAME_MININGSTATE_MININGSTATE_H
#define _GAME_MININGSTATE_MININGSTATE_H

#include "Core/State.hpp"

#include <array>
#include <map>

#include "nlohmann/json.hpp"

#include "Components/AnimatedSprite.h"
#include "Components/Switch.h"

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
        ~MiningState();

    protected:
        const SDL_Point MINING_TILE_START_POINT = {0, 64};
        const SDL_Point HAMMER_BUTTON = {217 * 2, 55 * 2};
        const SDL_Point PICKAXE_BUTTON = {217 * 2, 127 * 2};
        const SDL_Point HAMMER_SELECTED = {(217 * 2) - 12, (55 * 2) - 14};
        const SDL_Point PICKAXE_SELECTED = {(217 * 2) - 12, (127 * 2) - 14};
        double hp_ = 100.0;
        Tool tool_;
        std::map<std::string, std::vector<std::vector<int>>> treasure_layouts_;

        std::array<MiningLayer, 4> layers_;
        std::array<SpriteLayer, 4> layer_sprites_;
        SpriteLayer treasure_layer_;
        std::vector<std::vector<nge::TexturePtr>> layer_textures_;

        nge::AnimatedSprite hammer_cursor_;
        nge::AnimatedSprite pickaxe_cursor_;
        nge::AnimatedSprite hammer_selected_;
        nge::AnimatedSprite pickaxe_selected_;

        nge::Sprite background_;
        nge::SwitchPtr hammer_switch_, pickaxe_switch_;
        
        void Hit(SDL_Point point);
        SDL_Point GetMousePosInMine(int x, int y);
        bool PosIsValid(SDL_Point mousePos);
};


#endif