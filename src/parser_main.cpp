#include <iostream>
#include <string>
#include <bitset>
#include <thread>
#include <custom_listener.h>
#include "Leap.h"
#include "gesture_parser.h"
#include "g_bus_helper.h"


int main(int argc, char** argv)
{
    std::cout << "Press Enter to quit" << std::endl;
    
    auto * parser = new gesture_parser();

    std::cout << "Loading gestures..." << std::endl;

    // Start of gesture definitions
    hand_discrete hd_both_flat;
    hd_both_flat.set_l_hand_present(true);
    hd_both_flat.set_r_hand_present(true);
    hd_both_flat.set_l_open();
    hd_both_flat.set_r_open();
    hand_discrete hd_both_flat_ud;
    hd_both_flat_ud.set_l_hand_present(true);
    hd_both_flat_ud.set_r_hand_present(true);
    hd_both_flat_ud.set_l_open();
    hd_both_flat_ud.set_r_open();
    hd_both_flat_ud.set_l_roll(M_PI);
    hd_both_flat_ud.set_r_roll(M_PI);

    auto g_flip_up = new gesture("Flip both up", 100);
    g_flip_up->add_keyframe(hd_both_flat);
    g_flip_up->add_keyframe(hd_both_flat_ud);
    auto g_flip_down = new gesture("Flip both down", 100);
    g_flip_down->add_keyframe(hd_both_flat_ud);
    g_flip_down->add_keyframe(hd_both_flat);
    // End of gesture definitions

    parser->add_gesture(g_flip_down);
    parser->add_gesture(g_flip_up);

    std::cout << "Connecting to DBus..." << std::endl;
    g_bus_helper helper;
    helper.connect();

    std::cout << "Connecting to Leap Sensor..." << std::endl;
    custom_listener listener(parser, g_bus_helper::interface);
    Leap::Controller controller;
    controller.addListener(listener);

    std::cin.get();
    
    controller.removeListener(listener);

    return 0;
}
