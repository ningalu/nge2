#ifndef _STATE_H
#define _STATE_H

#include <memory>
#include <map>
#include <string>

#include "Graphics.h"
#include "Input.h"
#include "StateManager.h"

namespace nge {
    class State {
        public:
            State();
            State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics);

            virtual void Tick();
            virtual void Draw();
            void UpdatePreviousInput();
            void UpdateCurrentInput();

            ~State();
        protected:
            std::shared_ptr<StateManager> states_;
            std::shared_ptr<Graphics> graphics_;
            std::unique_ptr<Input> input_;
            SDL_Event event_buffer_;
            TexturePtr test;

            void UpdateInput();
            void Quit();
    };
}

#endif