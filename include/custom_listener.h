//
// Created by lucas on 17/05/19.
//

#ifndef GESTURE_PARSER_CUSTOM_LISTENER_H
#define GESTURE_PARSER_CUSTOM_LISTENER_H


#include "Leap.h"
#include "gesture_parser.h"
#include "gesture_gdbus_codegen.h"

class custom_listener : public Leap::Listener {
private:
    gesture_parser * g_parser;
    touchlessGesture *interface;
public:
    explicit custom_listener(gesture_parser *gesture_parser, touchlessGesture *m_interface);

    void onConnect(const Leap::Controller &controller) override;

    void onFrame(const Leap::Controller &controller) override;
};


#endif //GESTURE_PARSER_CUSTOM_LISTENER_H
