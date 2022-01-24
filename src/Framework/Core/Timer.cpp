#include "Timer.h"

using namespace nge;

Timer::Timer() {
    running_ = false;
}

void Timer::Start() {
    running_ = true;
}

void Timer::Update() {
    if (running_) {

    }
}

double Timer::GetDeltaTime() {
    return 1.0;
}

void Timer::Stop() {
    running_ = false;
}

void Timer::Reset() {

}

Timer::~Timer() {

}