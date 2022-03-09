#include "AnimationState.h"

namespace nge {
    AnimationState::AnimationState(
        int frameCount, 
        int repeats, 
        int subframes,
        int startingSubframe, 
        int startingFrame, 
        int startingRepeat
    ) : FrameCount(frameCount), Repeats(repeats), Subframes(subframes) {
        CurrentSubframe = startingSubframe;
        CurrentFrame = startingFrame;
        CurrentRepeat = startingRepeat;
    }

    void AnimationState::Advance() {
        CurrentSubframe++;
        if (CurrentSubframe >= Subframes) {
            CurrentSubframe = 0;
            CurrentFrame++;
            if (CurrentFrame >= FrameCount) {
                CurrentFrame = 0;
                CurrentRepeat++;
            }
        }
    }

    void AnimationState::Reset() {
        CurrentSubframe = 0;
        CurrentFrame = 0;
        CurrentRepeat = 0;
    }

    void AnimationState::Complete() {
        CurrentSubframe = Subframes;
        CurrentFrame = FrameCount;
        CurrentRepeat = Repeats;
    }

    bool AnimationState::IsCompatable(const AnimationState& state) {
        return (FrameCount == state.FrameCount)
        && (Repeats == state.Repeats)
        && (Subframes == state.Subframes);
    }

}