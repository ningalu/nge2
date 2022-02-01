#include "StateManager.h"

namespace nge {
    StateManager::StateManager() {
    }

    void StateManager::Advance(State* state) {
        states_.push_back(std::shared_ptr<State>(state));
    }

    void StateManager::Return() {
        states_.pop_back();
    }

    // This is probably pretty bad
    std::shared_ptr<State> StateManager::GetCurrentState() {
        return states_[states_.size() - 1];
    }

    StateManager::~StateManager() {
    }
}