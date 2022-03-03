#ifndef _ANIMATION_STATE_H
#define _ANIMATION_STATE_H

namespace nge {
    struct AnimationState {
        AnimationState(
            int frameCount, 
            int repeats = -1, 
            int frameDuration = 1, 
            int startingSubframe = 0, 
            int startingFrame = 0, 
            int startingRepeat = 0
        );
        const int FrameCount, Repeats, FrameDuration;
        int CurrentSubframe, CurrentFrame, CurrentRepeat;
    };
}

#endif