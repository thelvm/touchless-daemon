#include "gesture_parser.h"
#include <stdlib.h>

template <class T>
DataHistory<T>::DataHistory(size_t capacity)
{
    this->capacity = capacity;
    this->history = (T*)malloc(capacity * sizeof(T*));
    this->head_pos = 0;
}


GestureParser::GestureParser()
{
}

uint32_t GestureParser::Parse(const Leap::Frame frame)
{
    Leap::Hand leftHand, rightHand;

    uint32_t gestures = 0;

    if (!frame.hands().isEmpty())
    {
        for (int i = 0; i < frame.hands().count(); i++)
        {
            Leap::Hand hand = frame.hands()[i];

            if ( abs(hand.palmNormal().y) > 0.9 )
            {
                gestures += ( (hand.isLeft()) ? GESTURE_BASIC_L_HORIZONTAL : GESTURE_BASIC_R_HORIZONTAL);
            }
            if ( abs(hand.palmNormal().y) < 0.2 )
            {
                gestures += ( (hand.isLeft()) ? GESTURE_BASIC_L_VERTICAL : GESTURE_BASIC_R_VERTICAL);
            }
        }
    }
    return gestures;
}
