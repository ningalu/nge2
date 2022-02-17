#include "Game.hpp"
#include <iostream>

#include "Audio.h"
#include "Utility/SDL_EventExtensions.h"

namespace nge {
    Game::Game() {
        running_ = false;
        graphics_ = std::make_shared<Graphics>("NGE2 Demo", SDL_Rect{SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900});
        state_manager_ = std::make_shared<StateManager>();
        input_ = std::make_shared<Input>();
        Audio::Init();
    }

    std::shared_ptr<StateManager> Game::GetStateManager() {
        return state_manager_;
    }

    std::shared_ptr<Graphics> Game::GetGraphics() {
        return graphics_;
    }

    void Game::Start() {
        running_ = true;
        
        while (running_ && !state_manager_->IsEmpty()) {
            // Every 1/1000th of a second, update inputs and Tick the topmost State





            if (tick_timer_.GetElapsedTime() > (1.0 / 1000)) {
                ProcessInput();
                Tick();
                tick_timer_.Reset();
            }
            if (draw_timer_.GetElapsedTime() > (1.0f / 60)) {
                Draw();
                draw_timer_.Reset();
            }
            if (!state_manager_->GetCurrentState()->IsActive()) {
                state_manager_->Return();
            }
        }
    }

    void Game::Start(State* initialState) {
        Start(std::shared_ptr<State>(initialState));
    }

    void Game::Start(std::shared_ptr<State> initialState) {
        state_manager_->Advance(initialState);
        Start();
    }

    bool Game::IsRunning() {
        return running_;
    }

    void Game::End() {
        running_ = false;
    }

    void Game::ProcessInput() {
        state_manager_->GetCurrentState()->ProcessInput();
    }

    void Game::Tick() {
        
        state_manager_->GetCurrentState()->Tick();
        
    }

    void Game::Draw() {
        graphics_->Clear();
        state_manager_->GetCurrentState()->Draw();
        graphics_->Present();
    }

    Game::~Game() {
    }
}