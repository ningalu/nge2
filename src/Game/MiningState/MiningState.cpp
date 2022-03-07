#include "MiningState.h"

#include <vector>
#include <random>
#include <time.h>

#include "Core/Timer.h"
#include "Core/Utility/SDL_PointExtensions.h"

MiningState::MiningState(nge::State state) : nge::State(state) {

    // load mining texture tiles
    std::vector<nge::TexturePtr> t;
    for (int i = 0; i < 4; i++) {
        layer_textures_.push_back(t);
    }
    layer_textures_[0].push_back(graphics_->LoadTexture("resources/MiningState/invalid_tile.png"));
    layer_textures_[0].push_back(graphics_->LoadTexture("resources/MiningState/layer0_0.png"));
    layer_textures_[1].push_back(graphics_->LoadTexture("resources/MiningState/invalid_tile.png"));
    layer_textures_[1].push_back(graphics_->LoadTexture("resources/MiningState/layer1_0.png"));
    layer_textures_[1].push_back(graphics_->LoadTexture("resources/MiningState/layer1_1.png"));
    layer_textures_[2].push_back(graphics_->LoadTexture("resources/MiningState/invalid_tile.png"));
    layer_textures_[2].push_back(graphics_->LoadTexture("resources/MiningState/layer2_0.png"));
    layer_textures_[2].push_back(graphics_->LoadTexture("resources/MiningState/layer2_1.png"));
    layer_textures_[3].push_back(graphics_->LoadTexture("resources/MiningState/invalid_tile.png"));
    layer_textures_[3].push_back(graphics_->LoadTexture("resources/MiningState/layer3_0.png"));
    layer_textures_[3].push_back(graphics_->LoadTexture("resources/MiningState/layer3_1.png"));
    for (const auto &i : layer_textures_) {
        for (const auto &j : i) {
            std::cout << j.get() << "\n";
        }
    }

    

    // create mapping of tiles
    layers_.fill({});
    for (auto &row : layers_[0]) {
        row.fill(1);
    }
    for (auto &row : layers_[1]) {
        row.fill(1);
    }
    srand(time(NULL));
    for (auto l = 2; l < layers_.size(); l++) {
        for (auto i = 0; i < layers_[l].size(); i++) {
            for (auto j = 0; j < layers_[l][i].size(); j++) {
                if (layers_[l-1][i][j] != 0) {
                    layers_[l][i][j] = rand() % 3;
                }
            }
        }
    }

    for (auto i = 0; i < layers_.size(); i++) {
        std::cout << "\nLayer " << i << "\n";
        for (const auto &j : layers_[i]) {
            for (const auto &k : j) {
                std::cout << k;
            }
            std::cout << "\n";
        }
    }

    // create sprites based on the mapping
    SDL_Rect dst = {0, 0, 0, 0};
    SDL_QueryTexture(layer_textures_[0][0].get(), nullptr, nullptr, &dst.w, &dst.h);
    dst.w *= 2;
    dst.h *= 2;
    for (auto layer = 0; layer < layer_sprites_.size(); layer++) {
        for (auto row = 0; row < layer_sprites_[layer].size(); row++) {
            for (auto col = 0; col < layer_sprites_[layer][row].size(); col++) {
                dst.x = MINING_TILE_START_POINT.x + (col * dst.w);
                dst.y = MINING_TILE_START_POINT.y + (row * dst.h);
                layer_sprites_[layer][row][col] = nge::Sprite{
                    graphics_,
                    layer_textures_[layer][layers_[layer][row][col]],
                    nge::Graphics::FULL_TEXTURE,
                    dst
                };
            }
        }
    }

    graphics_->SetWindowSize(512, 384);
    cursor_ = nge::AnimatedSprite{
        graphics_, 
        "resources/MiningState/hammer_sprite.png", 
        nge::Graphics::FULL_TEXTURE,
        {input_->GetMouseX(), input_->GetMouseY(), 72, 64},
        4,
        1,
        5
    };
    background_ = nge::Sprite{
        graphics_,
        "resources/MiningState/background.png",
        nge::Graphics::FULL_TEXTURE,
        {0, 0, 512, 384}
    };

    

    RegisterKeyEvent(
        SDL_SCANCODE_ESCAPE, 
        nge::InputState::PRESSED, 
        [&](){
            Return();
        }
    );
}

static bool run = false;

void MiningState::Draw() {
    cursor_.AlignHorizontal(input_->GetMouseX());
    cursor_.AlignVertical(input_->GetMouseY());
    background_.Draw();

    SDL_Rect src = {0, 0, 0, 0};
    SDL_QueryTexture(layer_textures_[0][0].get(), nullptr, nullptr, &src.w, &src.h);
    SDL_Rect dst = {MINING_TILE_START_POINT.x, MINING_TILE_START_POINT.y, src.w * 2, src.h * 2};
    for (auto layer = 0; layer < layers_.size(); layer++) {
        for (auto row = 0; row < layers_[layer].size(); row++) {
            for (auto col = 0; col < layers_[layer][row].size(); col++) {
                if (layers_[layer][row][col] != 0) {
                    if (layer == (layers_.size() - 1)) {
                        layer_sprites_[layer][row][col].Draw();
                    } else {
                        if (layers_[layer + 1][row][col] == 0) {
                            layer_sprites_[layer][row][col].Draw();
                        }
                    }
                }
            }
        }
    }
    run = true;
    
    //cursor_.Draw();
}

void MiningState::Tick() {
    if (input_->MouseClicked(nge::MouseButton::LEFT)) {
        int row = (input_->GetMouseY() - MINING_TILE_START_POINT.y) / 32;
        int col = (input_->GetMouseX() - MINING_TILE_START_POINT.x) / 32;
        std::cout << SDL_Point{input_->GetMouseX(), input_->GetMouseY()} << "\n";
        std::cout << SDL_Point{row, col} << "\n";

        for (int i = layers_.size() - 1; i >= 0; i--) {
            if (layers_[i][row][col] != 0) {
                layers_[i][row][col] = 0;
                break;
            }
        }
    }
}
