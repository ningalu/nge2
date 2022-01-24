#ifndef _GAME_H
#define _GAME_H

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

            void PreDrawUpdate();
            void Draw();
            void PostDrawUpdate();

    };
}

#endif