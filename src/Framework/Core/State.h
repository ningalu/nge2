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

            bool IsActive();
            virtual void Tick();
            virtual void Draw();
            void UpdatePreviousInput();
            void UpdateCurrentInput();

            void RegisterClickable(std::shared_ptr<Clickable> clickable);
            void ProcessClickables();

            void RegisterKeyPressedEvent(SDL_Scancode key, std::function<void(void)> event);
            void RegisterKeyHeldEvent(SDL_Scancode key, std::function<void(void)> event);
            void ProcessKeyboardEvents();

            void ProcessInputs();

            virtual ~State();
        protected:
            bool active_;
            std::weak_ptr<StateManager> states_;
            std::shared_ptr<Graphics> graphics_;
            std::shared_ptr<Input> input_;
            SDL_Event event_buffer_;

            SoundPtr default_sound_;

            // Should this be shared? Or references?
            std::vector<std::shared_ptr<Clickable>> clickables_;

            std::vector<std::pair<SDL_Scancode, std::function<void(void)> > > keydown_events_;

            void Quit();
    };
}

#endif