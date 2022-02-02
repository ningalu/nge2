#include "Game.h"
#include <iostream>

namespace nge {
    Game::Game() {
        running_ = false;
        graphics_ = std::make_shared<Graphics>();
        state_manager_ = std::make_shared<StateManager>();
        input_ = std::make_shared<Input>();
        test = graphics_->LoadTexture("resources/stewie.jpg");
    }

    std::shared_ptr<StateManager> Game::GetStateManager() {
        return state_manager_;
    }

    std::shared_ptr<Graphics> Game::GetGraphics() {
        return graphics_;
    }

    void Game::Start(State* initialState) {
        Start(std::shared_ptr<State>(initialState));
    }

    void Game::Start(std::shared_ptr<State> initialState) {
        state_manager_->Advance(initialState);
        running_ = true;

        while (running_ && !state_manager_->IsEmpty()) {
            if (tick_timer_.GetElapsedTime() > (1.0 / 1000)) {
                ProcessInput();
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
        state_manager_->GetCurrentState()->Tick();
    }

    void Game::Draw() {
        graphics_->Clear();
        state_manager_->GetCurrentState()->Draw();
        graphics_->Present();
    }

    void Game::ProcessInput() {
        state_manager_->GetCurrentState()->UpdatePreviousInput();
        while (SDL_PollEvent(&event_buffer_)) {
            switch (event_buffer_.type) {
                case SDL_QUIT:
                    std::cout << "SDL_QUIT" << std::endl;
                    running_ = false;
                    break;
            }  
        }
        state_manager_->GetCurrentState()->UpdateCurrentInput();
    }

    Game::~Game() {

    }
}