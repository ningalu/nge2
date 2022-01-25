#ifndef _GAME_H
#define _GAME_H

#include "SDL2/SDL.h"

#include "Timer.h"

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

            Timer timer_;

            void PreDrawUpdate();
            void Draw();
            void PostDrawUpdate();

    };
}

#endif