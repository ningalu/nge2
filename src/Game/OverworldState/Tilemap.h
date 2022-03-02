#ifndef _TILEMAP_H
#define _TILEMAP_H

#include <memory>
#include <vector>

#include "Tileset.h"

namespace rpg {
    class Tilemap {
        public:
            Tilemap() = default;
            Tilemap(std::shared_ptr<nge::Graphics> graphics, std::shared_ptr<Tileset> tileset, std::vector<std::vector<int>> mapTileIds);

            SDL_Texture* const GetMapTexture() const;

            void Draw();

            ~Tilemap();

        private:
            std::shared_ptr<nge::Graphics> graphics_;
            std::shared_ptr<Tileset> tileset_;
            std::vector<std::vector<int>> map_tile_ids_;
            SDL_Texture *map_texture_;
    };
}

#endif