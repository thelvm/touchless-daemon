//
// Created by lucas on 23/06/19.
//

#include <iostream>

#include "touchless.hpp"
#include "DaemonGestureParserListener.hpp"

int main(int argc, char** argv)
{
    std::cout << "Starting daemon...\n";

    auto gestureParser = new touchless::GestureParser();
    auto gestureListener = new DaemonGestureParserListener();

    gestureParser->setListener(gestureListener);

    if (!touchless::isLeapDaemonRunning())
    {
        std::cout << "leapd is not running. Attempting to start it... (A password prompt may appear)\n";
        touchless::startLeapDaemon();
    }


    //touchless::stopLeapDaemon();

    return 0;
}
