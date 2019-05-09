#include "gesture_parser.h"
#include <stdlib.h>
#include <math.h>


hand_discrete * gesture_parser::parse_static(const Leap::Frame &frame)
{


    auto * pHandDiscrete = new hand_discrete();

    if (!frame.hands().isEmpty())
    {
        for (int i = 0; i < frame.hands().count(); i++)
        {
            Leap::Hand hand = frame.hands()[i];

            // Identifying presence of hand
            if (hand.isLeft())
            {
                pHandDiscrete->set_l_hand_present(true);
            }
            if (hand.isRight())
            {
                pHandDiscrete->set_r_hand_present(true);
            }

            // Roll discretization
            {
                if (hand.isLeft())
                {
                    pHandDiscrete->set_l_roll(hand.direction().roll());
                }
                else
                {
                    pHandDiscrete->set_r_roll(hand.direction().roll());
                }
            }

            // Pitch discretization
            {
                float pitch = hand.direction().pitch();
                auto d_pitch = (unsigned int)round(((pitch + M_PI) / M_PI_4) - 4);
                if (hand.isLeft())
                {
                    pHandDiscrete->set_l_pitch(d_pitch);
                }
                else
                {
                    pHandDiscrete->set_r_pitch(d_pitch);
                }
            }

            // Yaw discretization
            {
                float yaw = hand.direction().yaw();
                auto d_yaw = (unsigned int)round(((yaw + M_PI) / M_PI_4) - 4);
                if (hand.isLeft())
                {
                    pHandDiscrete->set_l_yaw(d_yaw);
                }
                else
                {
                    pHandDiscrete->set_r_yaw(d_yaw);
                }
            }

            // fingers
            {
                for (int j = 0; j < hand.fingers().count(); j++)
                {
                    Leap::Finger finger = hand.fingers()[j];

                    switch(finger.type()){
                        case Leap::Finger::TYPE_INDEX:
                            if (hand.isLeft())
                            {
                                pHandDiscrete->set_l_index(finger.isExtended());
                            }
                            else
                            {
                                pHandDiscrete->set_r_index(finger.isExtended());
                            }
                            break;
                        case Leap::Finger::TYPE_MIDDLE:
                            if (hand.isLeft())
                            {
                                pHandDiscrete->set_l_middle(finger.isExtended());
                            }
                            else
                            {
                                pHandDiscrete->set_r_middle(finger.isExtended());
                            }
                            break;
                        case Leap::Finger::TYPE_RING:
                            if (hand.isLeft())
                            {
                                pHandDiscrete->set_l_ring(finger.isExtended());
                            }
                            else
                            {
                                pHandDiscrete->set_r_ring(finger.isExtended());
                            }
                            break;
                        case Leap::Finger::TYPE_PINKY:
                            if (hand.isLeft())
                            {
                                pHandDiscrete->set_l_pinky(finger.isExtended());
                            }
                            else
                            {
                                pHandDiscrete->set_r_pinky(finger.isExtended());
                            }
                            break;
                        case Leap::Finger::TYPE_THUMB:
                            if (hand.isLeft())
                            {
                                pHandDiscrete->set_l_thumb(finger.isExtended());
                            }
                            else
                            {
                                pHandDiscrete->set_r_thumb(finger.isExtended());
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    return pHandDiscrete;
}

char * gesture_parser::parse(const Leap::Frame &frame) {
    hand_discrete * handDiscrete = parse_static(frame);
    if(!gestures.empty()) {
        for (auto & gesture : gestures) {
            if(gesture.test(handDiscrete)) {
                return gesture.name;
            }
        }
    }
    return nullptr;
}

void gesture_parser::add_gesture(const gesture& new_gesture) {
    gestures.push_back(new_gesture);
}


