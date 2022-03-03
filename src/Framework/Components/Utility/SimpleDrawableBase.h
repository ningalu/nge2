#ifndef _COMPONENTS_UTILITY_SIMPLEDRAWABLEBASE_H
#define _COMPONENTS_UTILITY_SIMPLEDRAWABLEBASE_H

#include "Core/Interfaces/Drawable.h"
#include "Core/Interfaces/Translatable.h"
#include "Core/Interfaces/Rotatable.h"

namespace nge {
    class SimpleDrawableBase : public Drawable, public Translatable, public Rotatable {
        public:
            // Drawable
            virtual bool Overlaps(SDL_Rect area);

            // Translatable
            virtual void SetX(int x);
            virtual void SetY(int y);
            virtual void MoveX(int x);
            virtual void MoveY(int y);
            virtual void AlignHorizontal(int x);
            virtual void AlignVertical(int y);

            // Rotatable
            virtual void Rotate(double angle);
            virtual void SetAngle(double angle);

            // Utility
            SDL_Rect GetDestRect();
            int GetX();
            int GetY();
            int GetW();
            int GetH();
            int GetCentreX();
            int GetCentreY();
            double GetAngle();

            virtual ~SimpleDrawableBase() = 0;

        protected:
            SDL_Rect src_, dst_;
            double angle_;
            SDL_Point rotation_centre_;
    };
}

#endif