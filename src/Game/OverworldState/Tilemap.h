#ifndef _TILEMAP_H
#define _TILEMAP_H

#include <memory>
#include <vector>

#include "Tileset.h"

namespace rpg {
    // With the current implementation, maps will be limited by the maximum of 8192x8192 texture sizes
    // Each tile in the map will consume additional memory since its added onto a texture
    // Animations will also be a pain in the ass
    class Tilemap {
        public:
            Tilemap() = default;
            Tilemap(std::shared_ptr<nge::Graphics> graphics, std::shared_ptr<Tileset> tileset, std::vector<std::vector<int>> mapTileIds);

            SDL_Texture* const GetMapTexture() const;
            int GetW() const;
            int GetH() const;

            void Draw();

            ~Tilemap();

        private:
            std::shared_ptr<nge::Graphics> graphics_;
            std::shared_ptr<Tileset> tileset_;
            std::vector<std::vector<int>> map_tile_ids_;
            SDL_Texture *map_texture_;
            int w_, h_;
    };
}

#endif