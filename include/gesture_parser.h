#ifndef GESTURE_PARSER_H_INCLUDED
#define GESTURE_PARSER_H_INCLUDED

#include "Leap.h"
#include "gestures.h"
#include <malloc.h>



template <class T>
class DataHistory
{
private:
    size_t head_pos;
    T* history;

public:
    size_t capacity;

    DataHistory<T>() : DataHistory<T>(100) {}
    DataHistory<T>(size_t capacity);

    void add(T frame);
    T read(size_t offset);

};

class GestureParser
{
    DataHistory<uint32_t> gesture_history;

public:
    GestureParser();

    uint32_t Parse(const Leap::Frame frame);
};

#endif // GESTURE_PARSER_H_INCLUDED
