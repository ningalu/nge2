#ifndef _TIMER_H
#define _TIMER_H

#include "stdint.h"

namespace nge {
    class Timer {
        public:
            Timer();

            void Start();
            void Update();
            double GetDeltaTime();
            void Stop();
            void Reset();

            ~Timer();
        private:
            bool running_;
            uint32_t start_ticks_;
            uint32_t elapsed_ticks_;
            double delta_time_;

    };
}

#endif