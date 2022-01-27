#include "Game.h"
#include <iostream>

namespace nge {
    Game::Game() {
        running_ = false;
        graphics_ = std::make_shared<Graphics>();
    }

    void Game::Start() {
        running_ = true;
        
        while (running_) {
            if (tick_timer_.GetElapsedTime() > (1.0 / 1000)) {
                Tick();
                tick_timer_.Reset();
            }
            if (draw_timer_.GetElapsedTime() > (1.0f / 60)) {
                Draw();
                draw_timer_.Reset();
            }

        }
    }

    bool Game::IsRunning() {
        return running_;
    }

    void Game::End() {
        running_ = false;
    }

    void Game::Tick() {

    }

    void Game::Draw() {
        graphics_->Clear();
        graphics_->Present();
    }

    Game::~Game() {

    }
}