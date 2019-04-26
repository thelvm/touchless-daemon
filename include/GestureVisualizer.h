#ifndef GESTUREVISUALIZER_H
#define GESTUREVISUALIZER_H

#include <stdint.h>
#include "gestures.h"

class GestureVisualizer
{
    public:
        GestureVisualizer();
        void show_static(Hand_discrete hand_discrete);

    protected:

    private:
        Hand_discrete previousStaticGesture;
};

#endif // GESTUREVISUALIZER_H
