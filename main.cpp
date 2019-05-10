#include <iostream>
#include <string>
#include <bitset>
#include "Leap.h"
#include "gesture_parser.h"
#include "gesture_visualizer.h"

gesture_parser* g_parser;
gesture_visualizer* g_vis;

class SampleListener : public Leap::Listener {
public:
    void onConnect(const Leap::Controller&) override;
    void onFrame(const Leap::Controller&) override;
};

void SampleListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Leap::Controller& controller) {
    const Leap::Frame frame = controller.frame();
    const char* g = g_parser->parse(frame);
    if(g != nullptr) {
        std::cout << g << std::endl;
    }
}

int main(int argc, char** argv)
{
    SampleListener listener;
    Leap::Controller controller;

    g_parser = new gesture_parser();
    g_vis = new gesture_visualizer();

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

    g_parser->add_gesture(g_flip_down);
    g_parser->add_gesture(g_flip_up);

    std::cout << "Connecting to Leap Sensor..." << std::endl;

    controller.addListener(listener);

    std::cout << "Press Enter to quit" << std::endl;
    std::cin.get();

    controller.removeListener(listener);

    return 0;
}
