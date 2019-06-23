//
// Created by lucas on 23/06/19.
//

#include <iostream>

#include "touchless.hpp"
#include "TouchlessDaemonListener.hpp"

int main(int argc, char** argv)
{
    std::cout << "Starting daemon...\n";

    auto gestureParser = new touchless::GestureParser();
    auto listener = new TouchlessDaemonListener();
    auto dbusInterface = new touchless::DbusInterface();

    gestureParser->setListener(listener);
    dbusInterface->setDaemonModeListener(listener);

    if (!touchless::isLeapDaemonRunning())
    {
        std::cout << "leapd is not running. Attempting to start it... (A password prompt may appear)\n";
        touchless::startLeapDaemon();
    }


    //touchless::stopLeapDaemon();

    return 0;
}
