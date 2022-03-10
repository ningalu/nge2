#include "Treasure.h"

Treasure::Treasure(
    nge::GraphicsPtr graphics, 
    std::string name, 
    std::vector<std::vector<int>>&& layout, 
    SDL_Point origin
) {
    graphics_ = graphics;
    name_ = name;
    layout_ = layout;
    for (auto &i : layout_) {
        sprites_.push_back({});
        for (auto j : i) {
            
        }
    }

}
    
void Treasure::Draw() {

}

bool Treasure::Overlaps(SDL_Rect area) {

}