#ifndef _FRAMEWORK_CORE_INPUT_H
#define _FRAMEWORK_CORE_INPUT_H

#include <string>
#include <vector>

#include "SDL2/SDL.h"
namespace nge {

enum MouseButton {
  LEFT = 0,
  RIGHT = 1,
  MIDDLE = 2,
  BACK = 3,
  FORWARD = 4
};

enum class InputState {
  PRESSED = 1 << 0,
  HELD = 1 << 1,
  RELEASED = 1 << 2
};
int operator&(const InputState &lhs, const InputState &rhs);
int operator|(const InputState &lhs, const InputState &rhs);

class Input {
public:
  Input();

  bool KeyPressed(SDL_Scancode scancode);
  bool KeyHeld(SDL_Scancode scancode);
  bool KeyReleased(SDL_Scancode scancode);

  bool MouseHeld(MouseButton button);
  bool MouseClicked(MouseButton button);
  bool MouseReleased(MouseButton button);

  int GetMouseX();
  int GetMouseY();
  SDL_Point GetMousePoint();

  void Update();
  void UpdatePrevInput();

  ~Input();

private:
  const Uint8 *current_keyboard_state_;
  Uint8 *previous_keyboard_state_;
  int keyboard_state_length_;
  Uint32 current_mouse_state_;
  Uint32 previous_mouse_state_;
  int mouse_x_;
  int mouse_y_;
};
} // namespace nge

#endif