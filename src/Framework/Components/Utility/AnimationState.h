#ifndef _ANIMATION_STATE_H
#define _ANIMATION_STATE_H

namespace nge {
    struct AnimationState {
        AnimationState(
            int frameCount, 
            int repeats = -1, 
            int subframes = 1, 
            int startingSubframe = 0, 
            int startingFrame = 0, 
            int startingRepeat = 0
        );

        void Advance();
        void Reset();

        const int FrameCount, Repeats, Subframes;
        int CurrentSubframe, CurrentFrame, CurrentRepeat;
    };
}

#endif