#ifndef _GAME_MININGSTATE_TREASURE_H
#define _GAME_MININGSTATE_TREASURE_H

#include <string>
#include <vector>

#include "SDL2/SDL.h"

#include "Framework/Core/Graphics.h"
#include "Framework/Core/Interfaces/Drawable.h"
#include "Framework/Components/Sprite.h"

class Treasure : public Drawable {
    public:
        Treasure(
            nge::GraphicsPtr graphics, 
            std::string name, 
            std::vector<std::vector<int>>&& layout, 
            SDL_Point origin
        );
    
        void Draw();
        bool Overlaps(SDL_Rect area);

    protected:
        nge::GraphicsPtr graphics_;
        std::string name_;
        std::vector<std::vector<int>> layout_;
        std::vector<std::vector<nge::Sprite>> sprites_;
};

#endif