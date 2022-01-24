#include "Game.h"
using namespace nge;

Game::Game() {
    running_ = false;
}

void Game::Start() {
    running_ = true;
    while(running_) {
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