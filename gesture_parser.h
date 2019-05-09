#ifndef GESTURE_PARSER_H_INCLUDED
#define GESTURE_PARSER_H_INCLUDED

#include "Leap.h"
#include "gestures.h"
#include "data_history.h"
#include <malloc.h>


class gesture_parser
{
    data_history<uint32_t> gesture_history;

public:
    gesture_parser();

    static hand_discrete * Parse_static(const Leap::Frame& frame);

};

#endif // GESTURE_PARSER_H_INCLUDED
