#include "gesture_visualizer.h"
#include "gestures.h"
#include <iostream>

gesture_visualizer::gesture_visualizer()
{
    this->previousStaticGesture = new hand_discrete;
}

void gesture_visualizer::show_static(hand_discrete * hd)
{
        if (hd->get_l_hand_present() || hd->get_r_hand_present())
        {
            if (hd->get_l_hand_present())
            {
                printf("Left: (%d %d %d) (%d %d %d %d %d) ",
                        hd->get_l_roll(),
                        hd->get_l_yaw(),
                        hd->get_l_pitch(),
                        hd->get_l_pinky(),
                        hd->get_l_ring(),
                        hd->get_l_middle(),
                        hd->get_l_index(),
                        hd->get_l_thumb());
            }

            if (hd->get_r_hand_present())
            {
                printf("Right: (%d %d %d) (%d %d %d %d %d) ",
                        hd->get_r_roll(),
                        hd->get_r_yaw(),
                        hd->get_r_pitch(),
                        hd->get_r_thumb(),
                        hd->get_r_index(),
                        hd->get_r_middle(),
                        hd->get_r_ring(),
                        hd->get_r_pinky());
            }
            printf("\n");
        }
        else
        {
            printf("-\n");
        }

}
