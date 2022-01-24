#include "Game.h"
#include <iostream>

using namespace nge;

Game::Game() {
    running_ = false;
    timer_.Start();
}

void Game::Start() {
    running_ = true;
    while(running_) {
        std::cout << timer_.GetDeltaTime() << std::endl;
        PreDrawUpdate();
        Draw();
        PostDrawUpdate();
    }
}

bool Game::IsRunning() {
    return running_;
}

void Game::End() {
    running_ = false;
}

Game::~Game() {

}

void Game::PreDrawUpdate() {

}

void Game::Draw() {

}

void Game::PostDrawUpdate() {

}