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
#include "StateManager.h"

namespace nge {
    class Game {
        public:
            Game();

            std::shared_ptr<StateManager> GetStateManager();
            std::shared_ptr<Graphics> GetGraphics();

            template<typename state, typename... Args>
            void SetInitialState(Args&&... args) {
                State temp(state_manager_, graphics_);
                std::shared_ptr<state> initialState = std::make_shared<state>(temp, std::forward<Args>(args)...);
                state_manager_->Advance(initialState);
            }

            void Start();
            void Start(State* initialState);
            void Start(std::shared_ptr<State> initialState);
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

            std::shared_ptr<StateManager> state_manager_;
            std::unique_ptr<State> initial_state_;
            
            void ProcessInput();
            void Tick();
            void Draw();
            

    };
}

#endif