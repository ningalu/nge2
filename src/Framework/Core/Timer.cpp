#include "Timer.h"

namespace nge {
Timer::Timer() {
  active_ = true;
  start_time_ = std::chrono::steady_clock::now();
}

void Timer::Start() {
  active_ = true;
  start_time_ = std::chrono::steady_clock::now();
}

double Timer::GetElapsedTime() const {
  return active_ ? static_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - start_time_).count()
                 : -1;
}

void Timer::Reset() {
  start_time_ = std::chrono::steady_clock::now();
}

void Timer::Stop() {
  active_ = false;
}

Timer::~Timer() {
}
} // namespace nge

std::ostream &operator<<(std::ostream &os, const nge::Timer &timer) {
  os << timer.GetElapsedTime();
  return os;
}