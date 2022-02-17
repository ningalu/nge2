#ifndef _STATE_H
#define _STATE_H

#include <memory>
#include <map>
#include <string>

#include "Graphics.h"
#include "Input.h"
#include "StateManager.h"
#include "Audio.h"
#include "InputInterfaces/Clickable.h"

namespace nge {
    class State {
        public:
            State();
            State(std::shared_ptr<StateManager> states, std::shared_ptr<Graphics> graphics);

            bool IsActive() const;
            bool GameEnded() const;

            virtual void ProcessInput();
            virtual void Tick();
            virtual void Draw();

            void RegisterClickable(std::shared_ptr<Clickable> clickable);
            void RegisterKeyEvent(SDL_Scancode key, int flags, std::function<void(void)> event);

            virtual ~State();

        protected:
            bool active_, quit_;
            std::string base_path_;
            std::weak_ptr<StateManager> states_;
            std::shared_ptr<Graphics> graphics_;
            std::shared_ptr<Input> input_;
            SDL_Event event_buffer_;

            SoundPtr default_sound_;

            // Should this be shared? Or references?
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