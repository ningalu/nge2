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

namespace nge {
    class Game {
        public:
            Game();

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

            void Tick();
            void Draw();

    };
}

#endif