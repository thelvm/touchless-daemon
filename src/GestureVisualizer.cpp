#include "GestureVisualizer.h"
#include "gestures.h"
#include <iostream>

GestureVisualizer::GestureVisualizer()
{
    this->previousGesture = 0;
}

void GestureVisualizer::show(uint32_t gesture)
{
    if (gesture != this->previousGesture)
    {
        if ( gesture == GESTURE_PARALLEL_HORIZONTAL )
        {
            std::cout << "_ _" << std::endl;
        }
        else if ( gesture == GESTURE_PARALLEL_VERTICAL )
        {
            std::cout << "| |" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
        this->previousGesture = gesture;
    }
}
