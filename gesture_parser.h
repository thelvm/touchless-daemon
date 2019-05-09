#ifndef GESTURE_PARSER_H_INCLUDED
#define GESTURE_PARSER_H_INCLUDED

#include "Leap.h"
#include "gestures.h"
#include <malloc.h>



template <class T>
class data_history
{
private:
    size_t head_pos;
    T* history;
    size_t size;
public:
    size_t getSize() const;

    void setSize(size_t mSize);

public:

    data_history<T>(): data_history(100) {};
    explicit data_history<T>(size_t size);

    void add(T frame);
    T read(size_t offset);

};

class gesture_parser
{
    data_history<uint32_t> gesture_history;

public:
    gesture_parser();

    static hand_discrete * Parse_static(const Leap::Frame& frame);

};

#endif // GESTURE_PARSER_H_INCLUDED
