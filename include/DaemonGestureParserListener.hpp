//
// Created by lucas on 23/06/19.
//

#ifndef TOUCHLESS_DAEMON_DAEMONGESTUREPARSERLISTENER_HPP
#define TOUCHLESS_DAEMON_DAEMONGESTUREPARSERLISTENER_HPP

#include "touchless.hpp"

class DaemonGestureParserListener : public touchless::GestureParserListener
{
public:
    void onGesture(char *t_gesture_name) override;

    void onConnect() override;

    void onDisconnect() override;
};

#endif //TOUCHLESS_DAEMON_DAEMONGESTUREPARSERLISTENER_HPP
