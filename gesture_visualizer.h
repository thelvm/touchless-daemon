#ifndef GESTUREVISUALIZER_H
#define GESTUREVISUALIZER_H

#include <stdint.h>
#include "gestures.h"

class gesture_visualizer
{
    public:
        gesture_visualizer();
        static void show_static(hand_discrete * hand_discrete);

    protected:

    private:
        hand_discrete * previousStaticGesture;
};

#endif // GESTUREVISUALIZER_H
