#include "MiningState.h"

#include <vector>
#include <random>
#include <time.h>
#include <memory>
#include <fstream>

#include "Core/Timer.h"
#include "Core/Utility/SDL_PointExtensions.h"

MiningState::MiningState(nge::State state) : nge::State(state) {
    graphics_->SetWindowSize(512, 384);
    tool_ = Tool::PICKAXE;

    srand(time(NULL));
    int treasures = (rand() % 4) + 1;

    std::ifstream treasureFile("resources/MiningState/treasure.json");
    nlohmann::json treasureJson = nlohmann::json::parse(treasureFile);
    std::cout << treasureJson["treasures"].dump(4) << "\n";
    std::vector<std::vector<int>> a = treasureJson["treasures"][0]["layout"].get<std::vector<std::vector<int>>>();
    for (auto i : a) {
        for (auto j : i) {
            std::cout << j;
        }
        std::cout << "\n";
    }
    for (auto &t : treasureJson["treasures"]) {
        treasure_layouts_.insert({t["name"], t["layout"].get<std::vector<std::vector<int>>>()});
    }
    for (auto &v : treasure_layouts_) {
        std::cout << v.first << ": \n";
        for (auto i : v.second) {
            for (auto j : i) {
                std::cout << j;
            }
            std::cout << "\n";
        }
    }

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
    // for (const auto &i : layer_textures_) {
    //     for (const auto &j : i) {
    //         std::cout << j.get() << "\n";
    //     }
    // }

    // create mapping of tiles
    layers_.fill({});
    for (auto &row : layers_[0]) {
        row.fill(1);
    }
    for (auto &row : layers_[1]) {
        row.fill(1);
    }
    for (auto l = 2; l < layers_.size(); l++) {
        for (auto i = 0; i < layers_[l].size(); i++) {
            for (auto j = 0; j < layers_[l][i].size(); j++) {
                if (layers_[l-1][i][j] != 0) {
                    layers_[l][i][j] = rand() % 3;
                }
            }
        }
    }
    // for (auto i = 0; i < layers_.size(); i++) {
    //     std::cout << "\nLayer " << i << "\n";
    //     for (const auto &j : layers_[i]) {
    //         for (const auto &k : j) {
    //             std::cout << k;
    //         }
    //         std::cout << "\n";
    //     }
    // }

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

    hammer_cursor_ = nge::AnimatedSprite{
        graphics_, 
        "resources/MiningState/hammer_sprite.png", 
        nge::Graphics::FULL_TEXTURE,
        {input_->GetMouseX(), input_->GetMouseY(), 72, 64},
        4,
        1,
        5
    };
    pickaxe_cursor_ = nge::AnimatedSprite{
        graphics_, 
        "resources/MiningState/pickaxe_sprite.png", 
        nge::Graphics::FULL_TEXTURE,
        {input_->GetMouseX(), input_->GetMouseY(), 72, 64},
        4,
        1,
        5
    };

    hammer_selected_ = nge::AnimatedSprite{
        graphics_,
        "resources/MiningState/hammer_selected.png",
        nge::Graphics::FULL_TEXTURE,
        {HAMMER_SELECTED.x, HAMMER_SELECTED.y, 92, 128},
        5,
        1,
        3
    };
    hammer_selected_.GetAnimationState()->Complete();

    pickaxe_selected_ = nge::AnimatedSprite{
        graphics_,
        "resources/MiningState/pickaxe_selected.png",
        nge::Graphics::FULL_TEXTURE,
        {PICKAXE_SELECTED.x, PICKAXE_SELECTED.y, 92, 128},
        5,
        1,
        3
    };
    pickaxe_selected_.GetAnimationState()->Complete();

    background_ = nge::Sprite{
        graphics_,
        "resources/MiningState/background.png",
        nge::Graphics::FULL_TEXTURE,
        {0, 0, 512, 384}
    };
    
    nge::SpritePtr hammerSwitchOn = std::make_unique<nge::Sprite>(
        graphics_,
        "resources/MiningState/hammer_on.png",
        nge::Graphics::FULL_TEXTURE,
        SDL_Rect{HAMMER_BUTTON.x, HAMMER_BUTTON.y, 34 * 2, 50 * 2}
    );
    nge::SpritePtr hammerSwitchOff = std::make_unique<nge::Sprite>(
        graphics_,
        "resources/MiningState/hammer_off.png",
        nge::Graphics::FULL_TEXTURE,
        SDL_Rect{HAMMER_BUTTON.x, HAMMER_BUTTON.y, 34 * 2, 50 * 2}
    );
    hammer_switch_ = std::make_shared<nge::Switch>(
        input_,
        std::move(hammerSwitchOn),
        std::move(hammerSwitchOff),
        SDL_Rect{HAMMER_BUTTON.x, HAMMER_BUTTON.y, 34 * 2, 50 * 2}
    );
    hammer_switch_->SetOnToggleOn([&](){
        hammer_selected_.Reset();
        tool_ = Tool::HAMMER;
        pickaxe_switch_->SetState(nge::SwitchState::OFF);
        pickaxe_switch_->Enable();
        hammer_switch_->Disable();
        
    });
    RegisterClickable(hammer_switch_);

    nge::SpritePtr pickaxeSwitchOn = std::make_unique<nge::Sprite>(
        graphics_,
        "resources/MiningState/pickaxe_on.png",
        nge::Graphics::FULL_TEXTURE,
        SDL_Rect{PICKAXE_BUTTON.x, PICKAXE_BUTTON.y, 34 * 2, 50 * 2}
    );
    nge::SpritePtr pickaxeSwitchOff = std::make_unique<nge::Sprite>(
        graphics_,
        "resources/MiningState/pickaxe_off.png",
        nge::Graphics::FULL_TEXTURE,
        SDL_Rect{PICKAXE_BUTTON.x, PICKAXE_BUTTON.y, 34 * 2, 50 * 2}
    );
    pickaxe_switch_ = std::make_shared<nge::Switch>(
        input_,
        std::move(pickaxeSwitchOn),
        std::move(pickaxeSwitchOff),
        SDL_Rect{PICKAXE_BUTTON.x, PICKAXE_BUTTON.y, 34 * 2, 50 * 2},
        nge::SwitchState::ON,
        false
    );
    pickaxe_switch_->SetOnToggleOn([&](){

        tool_ = Tool::PICKAXE;
        pickaxe_selected_.Reset();
        hammer_switch_->SetState(nge::SwitchState::OFF);
        hammer_switch_->Enable();
        pickaxe_switch_->Disable();
        
    });
    RegisterClickable(pickaxe_switch_);

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
    
    background_.Draw();
    hammer_switch_->Draw();
    pickaxe_switch_->Draw();
    hammer_selected_.Draw();
    pickaxe_selected_.Draw();

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
    switch (tool_) {
        case Tool::HAMMER:
            hammer_cursor_.AlignHorizontal(input_->GetMouseX());
            hammer_cursor_.AlignVertical(input_->GetMouseY());
            hammer_cursor_.Draw();
            break;
        case Tool::PICKAXE:
            pickaxe_cursor_.AlignHorizontal(input_->GetMouseX());
            pickaxe_cursor_.AlignVertical(input_->GetMouseY());
            pickaxe_cursor_.Draw();
            break;
    }
    
}

void MiningState::Tick() {
    if (input_->MouseClicked(nge::MouseButton::LEFT)) {
        SDL_Point p = GetMousePosInMine(input_->GetMouseX(), input_->GetMouseY());
        if (PosIsValid(p)) {
            Hit(p);
        }
        
    }
}

void MiningState::Hit(SDL_Point point) {
    std::vector<SDL_Point> struckTiles;
    struckTiles.reserve(9);
    struckTiles.push_back(point);

    SDL_Point temp = {point.x + 1, point.y};
    if (PosIsValid(temp)) {
        if ((rand() % 2) > 0) {
            struckTiles.push_back(temp);
        }
    }

    temp = {point.x - 1, point.y};
    if (PosIsValid(temp)) {
        if ((rand() % 2) > 0) {
            struckTiles.push_back(temp);
        }
    }

    temp = {point.x, point.y + 1};
    if (PosIsValid(temp)) {
        if ((rand() % 2) > 0) {
            struckTiles.push_back(temp);
        }
    }

    temp = {point.x, point.y - 1};
    if (PosIsValid(temp)) {
        if ((rand() % 2) > 0) {
            struckTiles.push_back(temp);
        }
    }
    
    if (tool_ == Tool::HAMMER) {

        temp = {point.x + 1, point.y + 1};
        if (PosIsValid(temp)) {
            if ((rand() % 2) > 0) {
                struckTiles.push_back(temp);
            }
        }

        temp = {point.x - 1, point.y + 1};
        if (PosIsValid(temp)) {
            if ((rand() % 2) > 0) {
                struckTiles.push_back(temp);
            }
        }

        temp = {point.x - 1, point.y - 1};
        if (PosIsValid(temp)) {
            if ((rand() % 2) > 0) {
                struckTiles.push_back(temp);
            }
        }

        // I typoed the following and am now paranoid enough to
        // use a temp var like this
        /*
        if (PosIsValid({point.x + 1, point.y - 1})) {
            struckTiles.push_back({point.x - 1, point.y - 1});
        }
        */
        temp = {point.x + 1, point.y - 1};
        if (PosIsValid(temp)) {
            if ((rand() % 2) > 0) {
                struckTiles.push_back(temp);
            }
        }
    }

    for (const auto &p : struckTiles) {
        for (int i = layers_.size() - 1; i > 0; i--) {
            if (layers_[i][p.y][p.x] != 0) {
                layers_[i][p.y][p.x] = 0;
                break;
            }
        }
    }
}

SDL_Point MiningState::GetMousePosInMine(int x, int y) {
    return {
        (input_->GetMouseX() / 32) - (MINING_TILE_START_POINT.x / 32),
        (input_->GetMouseY() / 32) - (MINING_TILE_START_POINT.y / 32)
    };
}

bool MiningState::PosIsValid(SDL_Point mousePos) {
    return ((mousePos.x >= 0) && (mousePos.y >= 0) && (mousePos.x < layers_[0][0].size()) && (mousePos.y < layers_[0].size()));
}

MiningState::~MiningState() {
}