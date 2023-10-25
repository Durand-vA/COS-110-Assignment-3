#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

template<class T>
Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
}

template<class T>
Queue<T>::Queue(const Queue<T> &other) {
    head = NULL;
    tail = NULL;
    if (!other.head)
        return;

    head = new Node<T>(other.head->data);
    Node<T>* ptr = other.head->next;
    Node<T>* newPtr = head;

    while (ptr) {
        newPtr->next = new Node<T>(ptr->data);
        newPtr = newPtr->next;
        ptr = ptr->next;
    }

    tail = ptr;
}

template<class T>
Queue<T>* Queue<T>::clone() const {
    Queue<T>* copy = new Queue<T>(*this);

    return copy;
}

template<class T>
Queue<T>::~Queue() {
    if (!head)
        return;
    Node<T>* ptr = head->next;
    while (ptr) {
        delete head;
        head = ptr;
        ptr = ptr->next;
    }
    delete head;
}

template<class T>
void Queue<T>::enqueue(T data) {
    if (!head) {
        head = new Node<T>(data);
        tail = head;
        return;
    }
    tail->next = new Node<T>(data);
    tail = tail->next;
}

template<class T>
T Queue<T>::dequeue() {
    if (!head)
        return T();
    T data = head->data;
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return data;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    return data;
}

template<class T>
const T Queue<T>::peek() const {
    return head->data;
}

template<class T>
bool Queue<T>::isEmpty() const {
    return !head;
}

#endif