#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"


template<class T>
Stack<T>::Stack() {
    top = NULL;
}

template<class T>
Stack<T>::Stack(const Stack<T> &other) {
    if (!other.top)
        return;

    Node<T>* ptr = other.top->next;
    top = new Node<T>(other.top->data);
    Node<T>* newPtr = top;

    while (ptr) {
        newPtr->next = new Node<T>(ptr->data);
        newPtr = newPtr->next;
        ptr = ptr->next;
    }
}

template<class T>
Stack<T>::~Stack() {
    if (!top)
        return;
    Node<T>* ptr = top->next;
    while (ptr) {
        delete top;
        top = ptr;
        ptr = ptr->next;
    }
    delete top;
}

template<class T>
void Stack<T>::push(T data) {
    top = new Node<T>(data, top);
}

template<class T>
T Stack<T>::pop() {
    if (!top) {
        return T();
    }
    T data = top->data;
    Node<T>* temp = top->next;
    delete top;
    top = temp;
    return data;
}

template<class T>
const T Stack<T>::peek() const {
    if (!top) {
        return T();
    }
    return top->data;
}

template<class T>
bool Stack<T>::isEmpty() const {
    return !top;
}




#endif // STACK_CPP