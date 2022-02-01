#ifndef _GAME_H
#define _GAME_H

#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "Timer.h"
#include "Graphics.h"
#include "Input.h"
#include "State.h"

namespace nge {
    class Game {
        public:
            Game(State* initialState);

            void Start();

            bool IsRunning();

            void End();

            ~Game();

        private:
            bool running_;

            Timer draw_timer_;
            Timer tick_timer_;

            std::shared_ptr<Graphics> graphics_;
            std::shared_ptr<Input> input_;

            SDL_Event event_buffer_;

            std::unique_ptr<State> initial_state_;

            TexturePtr test;

            void Tick();
            void Draw();

    };
}

#endif