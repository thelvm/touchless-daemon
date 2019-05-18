//
// Created by lucas on 09/05/19.
//

#ifndef GESTURE_PARSER_DATA_HISTORY_H
#define GESTURE_PARSER_DATA_HISTORY_H

#define DEFAULT_DATA_HISTORY_SIZE 100

#include <cstdlib>

template <class T>
class data_history
{
private:
    unsigned int head_pos;
    T* history;
    unsigned int size;

public:
    data_history<T>();
    explicit data_history<T>(unsigned int size);

    size_t get_size() const;

    void add(T frame);
    T head();
    T get(unsigned int offset);

};


#endif //GESTURE_PARSER_DATA_HISTORY_H
