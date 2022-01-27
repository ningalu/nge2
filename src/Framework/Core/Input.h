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
    int GetMouseX();
    int GetMouseY();
    void Update();
    void UpdatePrevInput();
    ~Input();

private:

    const Uint8* mKeyboardState;
    Uint8* mPrevKeyboardState;
    int mKeyLength;
    Uint32 mPrevMouseState;
    Uint32 mMouseState;
    int mMouseX;
    int mMouseY;
};

#endif