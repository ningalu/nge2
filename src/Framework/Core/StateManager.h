#ifndef _STATEMANAGER_H
#define _STATEMANAGER_H

#include <vector>
#include <memory>

#include "State.h"

namespace nge {
    class StateManager {
        public:
            StateManager();

            void Advance(State* state);
            void Return();
            std::shared_ptr<State> GetCurrentState();

            ~StateManager();
        private:
            std::vector<std::shared_ptr<State>> states_;
    };
}

#endif