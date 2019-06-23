//
// Created by lucas on 23/06/19.
//

#include "TouchlessDaemonListener.hpp"



void TouchlessDaemonListener::onNameOwned()
{
    DbusInterfaceDaemonModeListener::onNameOwned();
}

void TouchlessDaemonListener::onNameLost()
{
    DbusInterfaceDaemonModeListener::onNameLost();
}

void TouchlessDaemonListener::onGesture(char *t_gesture_name)
{
    GestureParserListener::onGesture(t_gesture_name);
}

void TouchlessDaemonListener::onCanParseGesture()
{
    GestureParserListener::onCanParseGesture();
}

void TouchlessDaemonListener::onCannotParseGesture()
{
    GestureParserListener::onCannotParseGesture();
}
