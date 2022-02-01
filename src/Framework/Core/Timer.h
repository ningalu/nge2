#ifndef _TIMER_H
#define _TIMER_H

#include "stdint.h"
#include <chrono>

namespace nge {
    class Timer {
        public:
            Timer();

            void Start();
            double GetElapsedTime();
            void Reset();
            void Stop();

            ~Timer();
        private:
            bool active_;
            std::chrono::time_point<std::chrono::steady_clock> start_time_;

    };
}

#endif