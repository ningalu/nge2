#ifndef _LISTENABLE_H
#define _LISTENABLE_H

#include <functional>

namespace nge {
    template <typename ...Args>
    class Listenable {
        public:
            virtual void Register(std::function<void(Args... args)> f) = 0;
            virtual void Emit(Args... args);
    };
}

// ListenableImpl<int, int> a;
// a.Register()

#endif