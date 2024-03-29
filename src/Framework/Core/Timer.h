#ifndef _FRAMEWORK_CORE_TIMER_H
#define _FRAMEWORK_CORE_TIMER_H

#include "stdint.h"
#include <chrono>
#include <ostream>

namespace nge {
class Timer {
public:
  Timer();

  void Start();
  double GetElapsedTime() const;
  void Reset();
  void Stop();

  ~Timer();

private:
  bool active_;
  std::chrono::time_point<std::chrono::steady_clock> start_time_;
};
} // namespace nge

std::ostream &operator<<(std::ostream &os, const nge::Timer &timer);

#endif