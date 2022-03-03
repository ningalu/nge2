#ifndef _GAME_OVERWORLDSTATE_OVERWORLDSTATE_H
#define _GAME_OVERWORLDSTATE_OVERWORLDSTATE_H

#include "Core/State.hpp"
#include "Tilemap.h"
#include "Tileset.h"

namespace rpg {
    class OverworldState : public nge::State {
        public:
            OverworldState(nge::State state);

            void Draw();

            ~OverworldState() = default;
    
        protected:
            std::shared_ptr<Tileset> tileset1_;
            Tilemap tilemap1_;
            Tilemap tilemap2_;

    };
}

#endif