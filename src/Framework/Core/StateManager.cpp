#include "StateManager.h"

namespace nge {
    StateManager::StateManager() {
    }

    void StateManager::Advance(State* state) {
        states_.push_back(state);
    }

    void StateManager::Return() {
        states_.pop_back();
    }

    State* StateManager::GetCurrentState() {
        return states_[states_.size() - 1];
    }

    StateManager::~StateManager() {
        for (int i = states_.size() - 1; i >= 0; i--) {
            delete states_[i];
        }
    }
}