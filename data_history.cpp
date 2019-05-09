//
// Created by lucas on 09/05/19.
//

#include "data_history.h"

template <class T>
data_history<T>::data_history()
{
    data_history::size = DEFAULT_DATA_HISTORY_SIZE;
    data_history::history = (T*)malloc(DEFAULT_DATA_HISTORY_SIZE * sizeof(T*));
    data_history::head_pos = 0;
}

template <class T>
data_history<T>::data_history(unsigned int capacity)
{
    data_history::size = capacity;
    data_history::history = (T*)malloc(capacity * sizeof(T*));
    data_history::head_pos = 0;
}

template<class T>
size_t data_history<T>::get_size() const {
    return size;
}

template<class T>
void data_history<T>::add(T frame) {
    history[head_pos] = frame;
    head_pos = (head_pos + 1) % size;
}

template<class T>
T data_history<T>::head() {
    return history[head_pos];
}

template<class T>
T data_history<T>::get(unsigned int offset) {
    int m_offset = head_pos - (offset % size);
    if (m_offset < 0)
        m_offset = size - m_offset;
    return history[m_offset];
}
