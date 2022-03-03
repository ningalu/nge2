#include "AnimationState.h"

namespace nge {
    AnimationState::AnimationState(
        int frameCount, 
        int repeats, 
        int frameDuration,
        int startingSubframe, 
        int startingFrame, 
        int startingRepeat
    ) : FrameCount(frameCount), Repeats(repeats), FrameDuration(frameDuration) {
        CurrentSubframe = startingSubframe;
        CurrentFrame = startingFrame;
        CurrentRepeat = startingRepeat;
    }
}