#ifndef _INPUT_H
#define _INPUT_H

#include <string>
#include <vector>

#include "SDL2/SDL.h"

class Input {
public:

    enum MouseButton {
        kLeft = 0,
        kRight = 1,
        kMiddle = 2,
        kBack = 3,
        kForward = 4
    };

    Input();
    bool KeyPressed(SDL_Scancode scancode);
    bool KeyDown(SDL_Scancode scancode);
    bool KeyReleased(SDL_Scancode scancode);
    bool MouseHeld(MouseButton button);
    bool MouseClicked(MouseButton button);
    bool MouseReleased(MouseButton button);
    const int& GetMouseX();
    const int& GetMouseY();
    void Update();
    void UpdatePrevInput();
    ~Input();

private:

    const Uint8* current_keyboard_state_;
    Uint8* previous_keyboard_state_;
    int keyboard_state_length_;
    Uint32 current_mouse_state_;
    Uint32 previous_mouse_state_;
    int mouse_x_;
    int mouse_y_;
};

#endif