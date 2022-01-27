#include "Input.h"
#include <iostream>

Input::Input() {
    mMouseState = 0;
    mPrevMouseState = 0;
    mKeyboardState = SDL_GetKeyboardState(&mKeyLength);
    mPrevKeyboardState = new Uint8[mKeyLength];
}

// Check if some SDL Scancode was pressed between the previous and current check
bool Input::KeyPressed(SDL_Scancode scancode) {
    return ((!(mPrevKeyboardState[scancode])) && (mKeyboardState[scancode]));
}

// Check if some SDL Scancode is currently pressed down
bool Input::KeyDown(SDL_Scancode scancode) {
    return mKeyboardState[scancode];
}

// Check if some SDL Scancode was released between the previous and current check
bool Input::KeyReleased(SDL_Scancode scancode) {
    return ((mPrevKeyboardState[scancode]) && (!(mKeyboardState[scancode])));    
}

bool Input::MouseClicked(MouseButton button) {
    Uint32 mask = 0;
    switch (button) {
        case kLeft:
            mask = SDL_BUTTON_LMASK;
            break;
        case kRight:
            mask = SDL_BUTTON_RMASK;
            break;
        case kMiddle:
            mask = SDL_BUTTON_MMASK;
            break;
        case kBack:
            mask = SDL_BUTTON_X1MASK;
            break;
        case kForward:
            mask = SDL_BUTTON_X2MASK;
            break;
    }
    return ((!(mPrevMouseState & mask)) && (mMouseState & mask));
}

bool Input::MouseHeld(MouseButton button) {
    Uint32 mask = 0;
    switch (button) {
        case kLeft:
            mask = SDL_BUTTON_LMASK;
            break;
        case kRight:
            mask = SDL_BUTTON_RMASK;
            break;
        case kMiddle:
            mask = SDL_BUTTON_MMASK;
            break;
        case kBack:
            mask = SDL_BUTTON_X1MASK;
            break;
        case kForward:
            mask = SDL_BUTTON_X2MASK;
            break;
    }
    return (mMouseState & mask) && (mPrevMouseState & mask);
}

bool Input::MouseReleased(MouseButton button) {
    Uint32 mask = 0;
    switch (button) {
        case kLeft:
            mask = SDL_BUTTON_LMASK;
            break;
        case kRight:
            mask = SDL_BUTTON_RMASK;
            break;
        case kMiddle:
            mask = SDL_BUTTON_MMASK;
            break;
        case kBack:
            mask = SDL_BUTTON_X1MASK;
            break;
        case kForward:
            mask = SDL_BUTTON_X2MASK;
            break;
    }
    return ((mPrevMouseState & mask) && (!(mMouseState & mask)));    
}

int Input::GetMouseX() {
    return mMouseX;
}

int Input::GetMouseY() {
    return mMouseY;
}

void Input::Update() {
    mMouseState = SDL_GetMouseState(&mMouseX, &mMouseY);
}

void Input::UpdatePrevInput() {
    memcpy(mPrevKeyboardState, mKeyboardState, mKeyLength);
    this->mPrevMouseState = mMouseState;
}

Input::~Input() {
    delete[] mPrevKeyboardState;
    mPrevKeyboardState = nullptr;
}