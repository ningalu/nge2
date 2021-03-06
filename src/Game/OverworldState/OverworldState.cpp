#include "OverworldState.h"

#include <vector>

#include "Core/Timer.h"
// benchmarking state
namespace rpg {
    OverworldState::OverworldState(nge::State state) : nge::State(state) {
        graphics_->SetWindowRect({SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600});
        tileset1_ = std::make_shared<Tileset>(graphics_, "resources/OverworldState/tileset.png", 32, 32);
        std::vector<std::vector<int>> tilemap1Ids{
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 36, 36, 1, 1, 1, 1, 1, 1},
            {1, 1, 36, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        tilemap1_ = Tilemap{graphics_, tileset1_, tilemap1Ids};
        std::vector<std::vector<int>> tilemap2Ids{
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 72, 73, 74, 75, 0, 0, 0, 0, 0},
            {0, 80, 81, 82, 83, 0, 0, 14, 14, 0},
            {0, 88, 89, 90, 91, 0, 14, 22, 22, 0},
            {0, 96, 97, 98, 99, 0, 22, 0, 0, 0},
            {0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 4, 128, 129, 129},
            {0, 0, 0, 0, 0, 0, 0, 136, 223, 223},
            {0, 0, 0, 4, 0, 0, 0, 136, 223, 223},
            {0, 0, 0, 0, 128, 129, 129, 190, 223, 223}
        };
        tilemap2_ = Tilemap{graphics_, tileset1_, tilemap2Ids};
    }

    void OverworldState::Draw() {
        nge::Timer t;
        
        SDL_Rect tempdst = {100, 100, 0, 0};
        SDL_QueryTexture(tilemap1_.GetMapTexture(), nullptr, nullptr, &tempdst.w, &tempdst.h);

        t.Reset();
        for (int i = 0; i < 35000; i++) {
            SDL_RenderCopy(graphics_->GetRenderer(), tilemap1_.GetMapTexture(), nullptr, &tempdst);
        }
        std::cout << "draws: " << t << "\n";

        SDL_QueryTexture(tilemap2_.GetMapTexture(), nullptr, nullptr, &tempdst.w, &tempdst.h);
        SDL_RenderCopy(graphics_->GetRenderer(), tilemap2_.GetMapTexture(), nullptr, &tempdst);
        std::cout << "total time: " << t << "\n";
    }
}