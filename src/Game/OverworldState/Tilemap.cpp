#include "Tilemap.h"

#include <iostream>

#include "Core/Utility/SDL_RectExtensions.h"

namespace rpg {
    Tilemap::Tilemap(
        std::shared_ptr<nge::Graphics> graphics, 
        std::shared_ptr<Tileset> tileset, 
        std::vector<std::vector<int>> mapTileIds
    ) : graphics_(graphics), tileset_(tileset), map_tile_ids_(mapTileIds) {
        w_ = mapTileIds[0].size() * tileset_->GetTileDimRect().w;
        h_ = mapTileIds.size() * tileset_->GetTileDimRect().h;
        map_texture_ = SDL_CreateTexture(
            graphics->GetRenderer(), 
            SDL_PIXELFORMAT_RGBA8888, 
            SDL_TEXTUREACCESS_TARGET, 
            w_, 
            h_
        );
        Draw();
    }

    SDL_Texture* const Tilemap::GetMapTexture() const {
        return map_texture_;
    }

    int Tilemap::GetW() const {
        return w_;
    }
    int Tilemap::GetH() const {
        return h_;
    }

    void Tilemap::Draw() {
        SDL_SetRenderTarget(graphics_->GetRenderer(), map_texture_);
        SDL_SetTextureBlendMode(map_texture_, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(graphics_->GetRenderer(), 0x00, 0x00, 0x00, 0);
        SDL_Rect src = {0, 0, 0, 0}, dst = tileset_->GetTileDimRect();
        for (auto i = 0; i < map_tile_ids_.size(); i++) {
            dst.y = i * dst.h;
            for (auto j = 0; j < map_tile_ids_[i].size(); j++) {
                src = tileset_->GetRectFromId(map_tile_ids_[i][j]);
                dst.x = j * dst.w;
                SDL_RenderCopy(graphics_->GetRenderer(), tileset_->GetTilesetTexture().get(), &src, &dst);
            }
        }
        SDL_SetRenderDrawColor(graphics_->GetRenderer(), 0xFF, 0xFF, 0xFF, 0);
        SDL_SetRenderTarget(graphics_->GetRenderer(), nullptr);
    }

    

    Tilemap::~Tilemap() {

    }
}