#include "Tileset.h"

#include <iostream>

namespace rpg {
    Tileset::Tileset(std::shared_ptr<nge::Graphics> graphics, const std::string& path, int tileW, int tileH) {
        tileset_dim_rect_ = {0, 0, 0, 0};
        tileset_ = graphics->LoadTexture(path);
        SDL_QueryTexture(tileset_.get(), nullptr, nullptr, &tileset_dim_rect_.w, &tileset_dim_rect_.h);
        tile_dim_rect_ = {0, 0, tileW, tileH};
    }

    const nge::TexturePtr& Tileset::GetTilesetTexture() const {
        return tileset_;
    }

    SDL_Rect Tileset::GetTileDimRect() const {
        return tile_dim_rect_;
    }

    SDL_Rect Tileset::GetRectFromId(int id) {
        return {(id % GetWidthInTiles()) * tile_dim_rect_.w, (id / GetWidthInTiles()) * tile_dim_rect_.h, tile_dim_rect_.w, tile_dim_rect_.h};
    }

    int Tileset::GetWidthInTiles() const {
        return tileset_dim_rect_.w / tile_dim_rect_.w;
    }

    int Tileset::GetHeightInTiles() const {
        return tileset_dim_rect_.h / tile_dim_rect_.h;
    }
    
    Tileset::~Tileset() {

    }
}