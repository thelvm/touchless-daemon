#ifndef GESTURES_H_INCLUDED
#define GESTURES_H_INCLUDED


struct Hand_discrete
{
    // Is left hand present
    unsigned int l_hand     : 1;
    // Left hand thumb. 0 is closed, 1 is extended
    unsigned int l_thumb    : 1;
    // Left hand index finger. 0 is closed, 1 is extended
    unsigned int l_index    : 1;
    // Left hand middle finger. 0 is closed, 1 is extended
    unsigned int l_middle   : 1;
    // Left hand ring finge. 0 is closed, 1 is extended
    unsigned int l_ring     : 1;
    // Left hand pinky finger. 0 is closed, 1 is extended
    unsigned int l_pinky    : 1;

    // Left hand roll.
    // 0 is flat palm down. Goes counter clockwise in 45° increments.
    unsigned int l_roll     : 3;
    // Left hand pitch.
    // 0 is flat palm down. Goes fingers up in 45° increments.
    unsigned int l_pitch     : 3;
    // Left hand yaw.
    // 0 is fingers pointing forward. Goes clockwise in 45° increments.
    unsigned int l_yaw      : 3;

    // Is the right hand present
    unsigned int r_hand     : 1;
    // Right hand thumb. 0 is closed, 1 is extended
    unsigned int r_thumb    : 1;
    // Right hand index finger. 0 is closed, 1 is extended
    unsigned int r_index    : 1;
    // Right hand middle finger. 0 is closed, 1 is extended
    unsigned int r_middle   : 1;
    // Right hand ring finger. 0 is closed, 1 is extended
    unsigned int r_ring     : 1;
    // Right hand pinky finger. 0 is closed, 1 is extended
    unsigned int r_pinky    : 1;

    // Right hand roll.
    // 0 is flat palm down. Goes clockwise in 45° increments.
    unsigned int r_roll     : 3;
    // Left hand pitch.
    // 0 is flat palm down. Goes fingers up in 45° increments.
    unsigned int r_pitch    : 3;
    // Left hand yaw.
    // 0 is fingers pointing forward. Goes clockwise in 45° increments.
    unsigned int r_yaw      : 3;


    bool operator==(const Hand_discrete& hd1)
    {
        if (hd1.l_hand      == l_hand   &&
            hd1.l_index     == l_index  &&
            hd1.l_middle    == l_middle &&
            hd1.l_ring      == l_ring   &&
            hd1.l_pinky     == l_pinky  &&
            hd1.l_roll      == l_roll   &&
            hd1.l_pitch      == l_pitch   &&
            hd1.l_yaw       == l_yaw    &&
            hd1.r_hand      == r_hand   &&
            hd1.r_index     == r_index  &&
            hd1.r_middle    == r_middle &&
            hd1.r_ring      == r_ring   &&
            hd1.r_pinky     == r_pinky  &&
            hd1.r_roll      == r_roll   &&
            hd1.r_pitch      == r_pitch   &&
            hd1.r_yaw       == r_yaw)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif // GESTURES_H_INCLUDED
