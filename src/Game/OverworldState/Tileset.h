#ifndef _TILESET_H
#define _TILESET_H

#include <string>

#include "SDL2/SDL.h"

#include "Graphics.h"

namespace rpg {
    class Tileset {
        public:
            Tileset(std::shared_ptr<nge::Graphics> graphics, const std::string& path, int tileW, int tileH);

            const nge::TexturePtr& GetTilesetTexture() const;
            SDL_Rect GetTileDimRect() const;
            SDL_Rect GetRectFromId(int id);
            int GetWidthInTiles() const;
            int GetHeightInTiles() const;

            ~Tileset();

        protected:
            nge::TexturePtr tileset_;
            SDL_Rect tileset_dim_rect_, tile_dim_rect_;
    };
}
    

#endif