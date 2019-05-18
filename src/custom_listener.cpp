//
// Created by lucas on 17/05/19.
//

#include "custom_listener.h"
#include "gesture_gdbus_codegen.h"
#include "gio/gio.h"

custom_listener::custom_listener(gesture_parser *gesture_parser, touchlessGesture *m_interface) : Listener() {
    g_parser = gesture_parser;
    interface = m_interface;
}

void custom_listener::onConnect(const Leap::Controller &controller) {
    std::cout << "Connected to Leap Motion Sensor!" << std::endl;
}

void custom_listener::onFrame(const Leap::Controller &controller) {
    const Leap::Frame frame = controller.frame();
    const char* g = g_parser->parse(frame);
    if(g != nullptr) {
        std::cout << g << std::endl;
        touchless_gesture_emit_changed(interface, g);
    }
}

