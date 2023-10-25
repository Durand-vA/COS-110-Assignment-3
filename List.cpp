#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

template<class T>
List<T> &List<T>::operator=(const List<T> &other) {
    if (this == &other)
        return *this;

    this->clear();
    int length = other.length();
    for (int i = 0; i < length; i++) {
        this->append(other[i]);
    }
}

#endif