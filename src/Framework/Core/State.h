#ifndef _STATE_H
#define _STATE_H

#include <memory>

#include "Graphics.h"

namespace nge {
    class State {
        public:
            State();
            State(std::shared_ptr<Graphics> graphics);

            void Tick();
            void Draw();

            ~State();
        private:
            std::shared_ptr<Graphics> graphics_;
            TexturePtr test;
    };
}

#endif