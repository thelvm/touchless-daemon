#ifndef GESTURE_PARSER_H_INCLUDED
#define GESTURE_PARSER_H_INCLUDED

#include "Leap.h"
#include "gestures.h"
#include <malloc.h>
#include <vector>

/// Parser for Leap Motion Sensor frames.
class gesture_parser
{
    std::vector<gesture*> gestures;

public:
    /// Adds a gesture to be checked each frame
    void add_gesture(gesture *new_gesture);

    /// Transforms a frame from the Leap motion sensor into a hand_discrete
    static hand_discrete * parse_static(const Leap::Frame &frame);

    /// Takes a frame from the Leap motion sensor and returns the corresponding gesture.
    /// If no gesture is currently detected, returns a null pointer
    const char * parse(const Leap::Frame &frame);
};

#endif // GESTURE_PARSER_H_INCLUDED
