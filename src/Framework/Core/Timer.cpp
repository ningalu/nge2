#include "Timer.h"

using namespace nge;

Timer::Timer() {
    start_time_ = std::chrono::steady_clock::now();
}

void Timer::Start() {
    start_time_ = std::chrono::steady_clock::now();
}

double Timer::GetElapsedTime() {
    return static_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - start_time_).count();
}

void Timer::Reset() {
    start_time_ = std::chrono::steady_clock::now();
}

Timer::~Timer() {

}