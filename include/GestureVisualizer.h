#ifndef GESTUREVISUALIZER_H
#define GESTUREVISUALIZER_H

#include <stdint.h>

class GestureVisualizer
{
    public:
        GestureVisualizer();
        void show(uint32_t gesture);

    protected:

    private:
        uint32_t previousGesture;
};

#endif // GESTUREVISUALIZER_H
