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
            if (hand.isRight())
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

            // fingers
            {
                for (int i = 0; i < hand.fingers().count(); i++)
                {
                    Leap::Finger finger = hand.fingers()[i];

                    switch(finger.type()){
                        case Leap::Finger::TYPE_INDEX:
                            if (hand.isLeft())
                            {
                                hand_discrete.l_index = finger.isExtended();
                            }
                            else
                            {
                                hand_discrete.r_index = finger.isExtended();
                            }
                            break;
                        case Leap::Finger::TYPE_MIDDLE:
                            if (hand.isLeft())
                            {
                                hand_discrete.l_middle = finger.isExtended();
                            }
                            else
                            {
                                hand_discrete.r_middle = finger.isExtended();
                            }
                            break;
                        case Leap::Finger::TYPE_RING:
                            if (hand.isLeft())
                            {
                                hand_discrete.l_ring = finger.isExtended();
                            }
                            else
                            {
                                hand_discrete.r_ring = finger.isExtended();
                            }
                            break;
                        case Leap::Finger::TYPE_PINKY:
                            if (hand.isLeft())
                            {
                                hand_discrete.l_pinky = finger.isExtended();
                            }
                            else
                            {
                                hand_discrete.r_pinky = finger.isExtended();
                            }
                            break;
                        case Leap::Finger::TYPE_THUMB:
                            if (hand.isLeft())
                            {
                                hand_discrete.l_thumb = finger.isExtended();
                            }
                            else
                            {
                                hand_discrete.r_thumb = finger.isExtended();
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    return hand_discrete;
}
