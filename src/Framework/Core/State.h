#ifndef _STATE_H
#define _STATE_H

#include <memory>
#include <map>
#include <string>

#include "Graphics.h"
#include "Input.h"

namespace nge {
    class State {
        public:
            State();
            State(std::shared_ptr<Graphics> graphics);

            void Tick();
            void Draw();

            ~State();
        private:
            std::map<std::string, State> children_;
            std::shared_ptr<Graphics> graphics_;
            std::unique_ptr<Input> input_;
            TexturePtr test;

            SDL_Event event_buffer_;

            void UpdateInput();
    };
}

#endif