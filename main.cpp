#include <iostream>
#include <string>
#include <bitset>
#include "Leap.h"
#include "gesture_parser.h"
#include "GestureVisualizer.h"

GestureParser* g_parser;
GestureVisualizer* g_vis;

class SampleListener : public Leap::Listener {
public:
    virtual void onConnect(const Leap::Controller&);
    virtual void onFrame(const Leap::Controller&);
};

void SampleListener::onConnect(const Leap::Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Leap::Controller& controller) {
    const Leap::Frame frame = controller.frame();
    Hand_discrete g = g_parser->Parse_static(frame);
    g_vis->show_static(g);
}

int main(int argc, char** argv)
{
    SampleListener listener;
    Leap::Controller controller;

    g_parser = new GestureParser();
    g_vis = new GestureVisualizer();

    std::cout << "Connecting to Leap Sensor..." << std::endl;

    controller.addListener(listener);

    std::cout << "Press Enter to quit" << std::endl;
    std::cin.get();

    controller.removeListener(listener);

    return 0;
}
