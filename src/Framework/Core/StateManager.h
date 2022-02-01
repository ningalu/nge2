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
            State* GetCurrentState();

            ~StateManager();
        private:
            std::vector<State*> states_;
    };
}

#endif