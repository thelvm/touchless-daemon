//
// Created by lucas on 23/06/19.
//

#ifndef TOUCHLESS_DAEMON_TOUCHLESSDAEMONLISTENER_HPP
#define TOUCHLESS_DAEMON_TOUCHLESSDAEMONLISTENER_HPP

#include "touchless.hpp"

class TouchlessDaemonListener : public touchless::GestureParserListener,
                                public touchless::DbusInterfaceDaemonModeListener
{
private:
    bool connectedToDbus;
    bool canParseGesture;

public:
    TouchlessDaemonListener();

    void onNameOwned() override;

    void onNameLost() override;

    void onGesture(char *t_gesture_name) override;

    void onCanParseGesture() override;

    void onCannotParseGesture() override;
};

#endif //TOUCHLESS_DAEMON_TOUCHLESSDAEMONLISTENER_HPP
