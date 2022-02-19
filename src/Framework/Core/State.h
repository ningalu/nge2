#ifndef _STATE_H
#define _STATE_H

#include <memory>
#include <map>
#include <string>

#include "Graphics.h"
#include "Input.h"
#include "StateManager.h"
#include "Audio.h"
#include "Interfaces/Clickable.h"

namespace nge {
    class State {
        public:
            State();
            State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics);
            void SetStateManager(std::shared_ptr<StateManager> states);
            void SetGraphics(std::shared_ptr<Graphics> graphics);

            // Game Status
            bool IsActive() const;
            bool GameEnded() const;

            // Behaviour
            virtual void ProcessInput();
            virtual void Tick();
            virtual void Draw();

            // Input
            void RegisterClickable(std::shared_ptr<Clickable> clickable);
            void RegisterKeyEvent(SDL_Scancode key, int flags, std::function<void(void)> event);
            void RegisterKeyEvent(SDL_Scancode key, InputState flags, std::function<void(void)> event);

            virtual ~State();

        protected:
            // External Resources
            std::weak_ptr<StateManager> states_;
            std::shared_ptr<Graphics> graphics_;

            // Generally internal resources
            bool active_, quit_;
            std::string base_path_;
            std::shared_ptr<Input> input_;
            SDL_Event event_buffer_;
            std::vector<std::shared_ptr<Clickable>> clickables_;
            std::vector<std::pair<SDL_Scancode, std::function<void(void)> > > keypressed_events_, keyheld_events_, keyreleased_events_;

            void RegisterKeyEvent(SDL_Scancode key, std::function<void(void)> event, std::vector<std::pair<SDL_Scancode, std::function<void(void)> > >& eventList);
            void ProcessClickables();
            void ProcessKeyboardEvents();
            void Return();
            void Quit();
    };
}

#endif