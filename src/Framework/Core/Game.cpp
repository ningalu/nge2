#include "Game.h"
#include <iostream>

namespace nge {
    Game::Game(State* initialState) {
        running_ = false;
        graphics_ = std::make_shared<Graphics>();
        std::cout << "Game: " << graphics_.get() << std::endl;
        initial_state_ = std::make_unique<State>(graphics_);
        input_ = std::make_shared<Input>();
        std::cout << graphics_->GetWindowWidth() << std::endl;
        std::cout << "Creating Game.test" << std::endl;
        test = graphics_->LoadTexture("resources/stewie.jpg");
        std::cout << "Created Game.test" << std::endl;
    }

    void Game::Start() {
        running_ = true;

        while (running_) {
            if (tick_timer_.GetElapsedTime() > (1.0 / 1000)) {
                input_->UpdatePrevInput();
                while (SDL_PollEvent(&event_buffer_)) {
                    switch (event_buffer_.type) {
                        case SDL_QUIT:
                            std::cout << "SDL_QUIT" << std::endl;
                            running_ = false;
                            break;
                    }  
                }
                input_->Update();
                if (input_->KeyPressed(SDL_SCANCODE_A)) {
                    std::cout << "A" << std::endl;
                }
                Tick();
                tick_timer_.Reset();
            }
            if (draw_timer_.GetElapsedTime() > (1.0f / 1)) {
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
        graphics_->DrawTexture(test.get(), nullptr, nullptr);
        graphics_->Present();
    }

    Game::~Game() {

    }
}