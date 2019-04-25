#ifndef GESTURES_H_INCLUDED
#define GESTURES_H_INCLUDED

#include <stdint.h>
// Declaration of basic gestures. Their combination creates more complex gestures
static const uint32_t GESTURE_BASIC_L_VERTICAL      = 1 << 0;
static const uint32_t GESTURE_BASIC_R_VERTICAL      = 1 << 1;
static const uint32_t GESTURE_BASIC_L_HORIZONTAL    = 1 << 2;
static const uint32_t GESTURE_BASIC_R_HORIZONTAL    = 1 << 3;

static const uint32_t GESTURE_PARALLEL_HORIZONTAL   = GESTURE_BASIC_L_HORIZONTAL    |   GESTURE_BASIC_R_HORIZONTAL;
static const uint32_t GESTURE_PARALLEL_VERTICAL     = GESTURE_BASIC_L_VERTICAL      |   GESTURE_BASIC_R_VERTICAL;

#endif // GESTURES_H_INCLUDED
