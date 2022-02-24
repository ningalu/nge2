#ifndef _STATEMANAGER_H
#define _STATEMANAGER_H

#include <vector>
#include <memory>

namespace nge {
    class State;
    class StateManager {
        public:
            StateManager();

            void Advance(std::shared_ptr<State> state);

            void Return();
            std::shared_ptr<State>& GetCurrentState();
            bool IsEmpty();

            ~StateManager();
        private:
            std::vector<std::shared_ptr<State>> states_;
    };
}

#endif