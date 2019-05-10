#ifndef GESTURE_PARSER_H_INCLUDED
#define GESTURE_PARSER_H_INCLUDED

#include "Leap.h"
#include "gestures.h"
#include "data_history.h"
#include <malloc.h>
#include <vector>


class gesture_parser
{
    std::vector<gesture*> gestures;

public:
    void add_gesture(gesture *new_gesture);
    static hand_discrete * parse_static(const Leap::Frame &frame);
    const char * parse(const Leap::Frame &frame);
};

#endif // GESTURE_PARSER_H_INCLUDED
