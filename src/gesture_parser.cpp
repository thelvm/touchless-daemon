#include "gesture_parser.h"
#include <stdlib.h>
#include <math.h>

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

Hand_discrete GestureParser::Parse_static(const Leap::Frame frame)
{
    Leap::Hand leftHand, rightHand;

    Hand_discrete hand_discrete;

    if (!frame.hands().isEmpty())
    {
        for (int i = 0; i < frame.hands().count(); i++)
        {
            Leap::Hand hand = frame.hands()[i];

            // Identifing presence of hand
            if (hand.isLeft())
            {
                hand_discrete.l_hand = 1;
            }
            else
            {
                hand_discrete.r_hand = 1;
            }

            // Roll discretization
            {
                float roll = hand.palmNormal().roll();
                unsigned int d_roll = (unsigned int)round((roll + M_PI) / M_PI_4);
                if (hand.isLeft())
                {
                    hand_discrete.l_roll = d_roll;
                }
                else
                {
                    hand_discrete.r_roll = d_roll;
                }
            }

            // Pitch discretization
            {
                float pitch = hand.direction().pitch();
                unsigned int d_pitch = (unsigned int)round(((pitch + M_PI) / M_PI_4) - 4);
                if (hand.isLeft())
                {
                    hand_discrete.l_pitch = d_pitch;
                }
                else
                {
                    hand_discrete.r_pitch = d_pitch;
                }
            }

            // Yaw discretization
            {
                float yaw = hand.direction().yaw();
                unsigned int d_yaw = (unsigned int)round(((yaw + M_PI) / M_PI_4) - 4);
                if (hand.isLeft())
                {
                    hand_discrete.l_yaw = d_yaw;
                }
                else
                {
                    hand_discrete.r_yaw = d_yaw;
                }
            }
        }
    }
    return hand_discrete;
}
