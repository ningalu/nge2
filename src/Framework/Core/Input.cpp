#include "Input.h"
#include <iostream>

Input::Input() {
    current_mouse_state_ = 0;
    previous_mouse_state_ = 0;
    current_keyboard_state_ = SDL_GetKeyboardState(&keyboard_state_length_);
    previous_keyboard_state_ = new Uint8[keyboard_state_length_];
}

// Check if some SDL Scancode was pressed between the previous and current check
bool Input::KeyPressed(SDL_Scancode scancode) {
    return ((!(previous_keyboard_state_[scancode])) && (current_keyboard_state_[scancode]));
}

// Check if some SDL Scancode is currently pressed down
bool Input::KeyDown(SDL_Scancode scancode) {
    return current_keyboard_state_[scancode];
}

// Check if some SDL Scancode was released between the previous and current check
bool Input::KeyReleased(SDL_Scancode scancode) {
    return ((previous_keyboard_state_[scancode]) && (!(current_keyboard_state_[scancode])));    
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
    return ((!(previous_mouse_state_ & mask)) && (current_mouse_state_ & mask));
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
    return (current_mouse_state_ & mask) && (previous_mouse_state_ & mask);
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
    return ((previous_mouse_state_ & mask) && (!(current_mouse_state_ & mask)));    
}

int Input::GetMouseX() {
    return mouse_x_;
}

int Input::GetMouseY() {
    return mouse_y_;
}

void Input::Update() {
    current_mouse_state_ = SDL_GetMouseState(&mouse_x_, &mouse_y_);
}

void Input::UpdatePrevInput() {
    memcpy(previous_keyboard_state_, current_keyboard_state_, keyboard_state_length_);
    this->previous_mouse_state_ = current_mouse_state_;
}

Input::~Input() {
    delete[] previous_keyboard_state_;
    previous_keyboard_state_ = nullptr;
}