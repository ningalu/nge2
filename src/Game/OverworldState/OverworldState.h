#ifndef _OVERWORLDSTATE_H
#define _OVERWORLDSTATE_H

#include "State.hpp"
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

    };
}

#endif