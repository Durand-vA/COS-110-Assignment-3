#ifndef CLINKEDLIST_CPP
#define CLINKEDLIST_CPP

#include "CLinkedList.h"

template<class T>
CLinkedList<T>::CLinkedList() {
    head = NULL;
}

template<class T>
CLinkedList<T>::~CLinkedList() {
    if (head) {
        Node<T>* ptr = head->next;
        Node<T>* next;
        while (ptr && ptr != head) {
            next = ptr->next;
            delete ptr;
            ptr = next;
        }
        delete ptr;
    }
}
/**
 * @brief Prepends the given data to the list
 *
 * @tparam T
 */
template<class T>
void CLinkedList<T>::prepend(T data) {
    if (!head) {
        head = new Node<T>(data);
        head->next = head;
        return;
    }
    Node<T>* tail = head->next;
    while (tail->next != head) {
        tail = tail->next;
    }

    head = new Node<T>(data, head);
    tail->next = head;
}
/**
 * @brief Appends the given data to the list
 *
 * @tparam T
 */
template<class T>
void CLinkedList<T>::append(T data) {
    if (!head) {
        head = new Node<T>(data);
        head->next = head;
        return;
    }
    Node<T>* tail = head->next;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = new Node<T>(data, head);
}

template<class T>
void CLinkedList<T>::remove(int index) {
    int length = this->length();
    if (index < 0 || index >= length) {
        return;
    }
    if (length == 1) {
        delete head;
        head = NULL;
        return;
    }

    Node<T>* ptr = head;
    Node<T>* prev = NULL;
    int count = 0;
    while (count < index && ptr && ptr->next != head) {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (prev) {
        prev->next = ptr->next;
    } else {
        Node<T>* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = ptr->next;
        head = ptr->next;
    }
    delete ptr;
}

template<class T>
void CLinkedList<T>::insert(T data, int index) {
    int length = this->length();
    if (index < 0 || index > length) {
        return;
    }
    if (index == length) {
        append(data);
        return;
    }

    Node<T>* ptr = head;
    Node<T>* prev = NULL;
    int count = 0;
    while (count < index && ptr && ptr->next != head) {
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (!prev) {
        prepend(data);
    } else {
        prev->next = new Node<T>(data, ptr);
    }
}

template<class T>
void CLinkedList<T>::removeElements(T data) {
    if (!head) {
        return;
    }
    Node<T>* ptr = head;
    int count = 0;
    while (ptr && ptr->next != head) {
        Node<T>* nextNode = ptr->next;
        if (ptr->data == data) {
            remove(count);
        } else {
            count++;
        }
        if (head)
            ptr = nextNode;
        else {
            ptr = NULL;
        }
    }
    if (ptr->data == data) {
        remove(count);
    }
}

template<class T>
void CLinkedList<T>::print() const {
    if (!head) {
        std::cout << "Empty\n";
        return;
    }

    std::cout << head->data;
    Node<T>* ptr = head->next;

    while (ptr && ptr != head) {
        std::cout << " -> ";
        std::cout << ptr->data;
        ptr = ptr->next;
    }
    std::cout << "\n";
}

template<class T>
void CLinkedList<T>::reverse() {
    if (!head) {
        return;
    }
    Node<T>* ptr = head;
    CLinkedList<T> reversed;
    reversed.prepend(ptr->data);

    ptr = ptr->next;

    while (ptr && ptr != head) {
        reversed.prepend(ptr->data);
        ptr = ptr->next;
    }
    *this = reversed;
}

template<class T>
void CLinkedList<T>::clear() {
    if (!head)
        return;
    Node<T>* ptr = head->next;
    while (ptr && ptr != head) {
        Node<T>* next = ptr->next;
        delete ptr;
        ptr = next;
    }
    delete head;
    head = NULL;
}

template<class T>
int CLinkedList<T>::length() const {
    if (!head) {
        return 0;
    }
    Node<T>* ptr = head;
    int count = 0;
    do {
        ptr = ptr->next;
        count++;
    } while (ptr != head);
    return count;
}

template<class T>
T CLinkedList<T>::get(int index) const {
    if (!head) {
        return T();
    }
//    if (index == 0) {
//        return head->data;
//    }

    Node<T>* ptr = head;
    int idx = 0;
    while (ptr && idx < index && ptr->next != head) {
        ptr = ptr->next;
        idx++;
    }

    if (idx == index) {
        return ptr->data;
    } else {
        return T();
    }
}

template<class T>
T CLinkedList<T>::operator[](int index) const {
    if (!head) {
        return T();
    }
//    if (index == 0) {
//        return head->data;
//    }

    Node<T>* ptr = head;
    int idx = 0;
    while (ptr && idx < index && ptr->next != head) {
        ptr = ptr->next;
        idx++;
    }

    if (idx == index) {
        return ptr->data;
    } else {
        return T();
    }
}

enum operation {less, greater, lessEqual, greaterEqual,
        equal, notEqual};

template<class T>
bool match(T data, T query, operation p) {
    switch (p) {
        case less:
            return data < query;
        case greater:
            return data > query;
        case lessEqual:
            return data <= query;
        case greaterEqual:
            return data >= query;
        case equal:
            return data == query;
        case notEqual:
            return data != query;
        default:
            return false;
    }
}
/**
 * @brief Filters the list based on the given operation and query
 *
 * @tparam T
 * @param op ">", "<", ">=", "<=", "==", "!="
 * @param query
 */
template<class T>
void CLinkedList<T>::filter(std::string op, T query) {
    operation p;
    if (op == "<") {
        p = less;
    } else if (op == ">") {
        p = greater;
    } else if (op == "<=") {
        p = lessEqual;
    } else if (op == ">=") {
        p = greaterEqual;
    } else if (op == "==") {
        p = equal;
    } else if (op == "!=") {
        p = notEqual;
    } else {
        return;
    }

    Node<T>* ptr = head;
    int count = 0;
    while (ptr && ptr->next != head) {
        Node<T>* nextNode = ptr->next;
        if (!match(ptr->data, query, p)) {
            remove(count);
        } else {
            count++;
        }
        if (head)
            ptr = nextNode;
        else {
            ptr = NULL;
        }
    }
    if (!match(ptr->data, query, p)) {
        remove(count);
    }
}

template<class T>
void CLinkedList<T>::swap(int index1, int index2) {
    if (!head)
        return;
    int length = this->length();
    if (index1 == index2 || index1 < 0 || index1 >= length || index2 < 0 || index2 >= length) {
        return;
    }
    Node<T>* ptr1;
    Node<T>* ptr2;

    Node<T>* ptr = head;
    int count = 0;
    do {
        if (count == index1) {
            ptr1 = ptr;
        }
        if (count == index2) {
            ptr2 = ptr;
        }
        ptr = ptr->next;
        count++;
    } while (ptr != head);

    T temp = ptr2->data;
    ptr2->data = ptr1->data;
    ptr1->data = temp;
}

template<class T>
void CLinkedList<T>::slice(int start, int end) {
    if (!head)
        return;

    int length = this->length();
    if (start > end || start < 0 || start >= length || end < 0 || end >= length)
        return;

    Node<T>* ptr = head;

    CLinkedList<T> sliced;

    int idx = 0, count = 0;
    do {
        if (idx >= start) {
            sliced.append(ptr->data);
        } else {
            count++;
        }
        idx++;
        ptr = ptr->next;
    } while (idx <= end && ptr != head);

    *this = sliced;
}

template<class T>
void CLinkedList<T>::RRotate(int k) {
    int length = this->length();
    LRotate(length - (k%length));
}

template<class T>
void CLinkedList<T>::LRotate(int k) {
    if (k <= 0 || !head)
        return;

    int length = this->length();
    k %= length;

    for (int i = 0; i < k; i++) {
        head = head->next;
    }
}

template<class T>
CLinkedList<T> &CLinkedList<T>::operator=(const CLinkedList<T> &other) {
    if (this == &other)
        return *this;

    this->clear();

    Node<T>* ptr = other.head;

    if (ptr) {
        this->append(ptr->data);
        ptr = ptr->next;
    }

    while (ptr && ptr != other.head) {
        this->append(ptr->data);
        ptr = ptr->next;
    }

    return *this;
}

template<class T>
int contains(T** arr, T data, int length) {
    for (int i = 0; i < length; i++) {
        if (!arr[i])
            return -1;
        if ((*arr[i]) == data) {
            return i;
        }
    }
    return -1;
}

template<class T>
void countElement(T** arr, int** elementCount, T data, int length) {
    int idx = contains(arr, data, length);
    if (idx == -1) {
        int index = 0;
        bool found = false;
        while (!found) {
            if (elementCount[index]) {
                index++;
            } else {
                found = true;
            }
        }
        T* temp = new T;
        *temp = data;
        arr[index] = temp;
        elementCount[index] = new int(1);
    } else {
        (*elementCount[idx])++;
    }
}

template<class T>
void unCountElement(T** arr, int** elementCount, T data, int length) {
    int idx = contains(arr, data, length);
    if (idx == -1) {
        int index = 0;
        bool found = false;
        while (!found) {
            if (elementCount[index]) {
                index++;
            } else {
                found = true;
            }
        }
        T* temp = new T;
        *temp = data;
        arr[index] = temp;
        elementCount[index] = new int(-1);
    } else {
        (*elementCount[idx])--;
    }
}

template<class T>
bool CLinkedList<T>::operator==(const CLinkedList<T> &other) const {
    if (this == &other)
        return true;

    int length = this->length();
    if (length != other.length())
        return false;

    if (!head)
        return true;

    T** arr = new T*[length];
    int** elementCount = new int*[length];
    for (int i = 0; i < length; i++) {
        arr[i] = NULL;
        elementCount[i] = NULL;
    }

    Node<T>* ptr = head;
    do {
        countElement(arr, elementCount, ptr->data, length);
        ptr = ptr->next;
    } while (ptr != head);

    ptr = other.head;
    do {
        unCountElement(arr, elementCount, ptr->data, length);
        ptr = ptr->next;
    } while (ptr != other.head);

    bool equal = true;
    for (int i = 0; i < length; i++) {
        equal = equal && (*elementCount[i] == 0);
    }

    for (int i = 0; i < length; i++) {
        if (elementCount[i])
            delete elementCount[i];
        if (arr[i])
            delete arr[i];
    }
    delete [] arr;
    delete [] elementCount;

    return equal;
}

template<class T>
void CLinkedList<T>::operator+=(const CLinkedList<T> &other) {
    if (!other.head || this == &other) {
        return;
    }

    Node<T>* ptr = other.head;
    do {
        this->append(ptr->data);
        ptr = ptr->next;
    } while (ptr != other.head);
}

template<class T>
CLinkedList<T>* CLinkedList<T>::operator-(const CLinkedList<T> &other) const {
    CLinkedList<T>* out = new CLinkedList<T>;
    *out = *this;

    if (!other.head)
        return out;

    Node<T>* ptr = other.head;
    do {
        out->removeElements(ptr->data);
        ptr = ptr->next;
    } while (ptr != other.head);

    return out;
}

template<class T>
void CLinkedList<T>::removeDuplicates() {
    if (!head)
        return;

    Node<T>* ptr = head;
    Node<T>* prev = NULL;

    do {
        T data = ptr->data;
        this->removeElements(data);
        if (!prev) {
            this->prepend(data);
            ptr = head;
        } else {
            prev->next = new Node<T>(data, prev->next);
            ptr = prev->next;
        }
        prev = ptr;
        ptr = ptr->next;
    } while (ptr != head);

}

template<class T>
void CLinkedList<T>::consume(CLinkedList<T> &other) {
    if (!other.head || this == &other) {
        return;
    }

    Node<T>* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    Node<T>* otherTail = other.head;
    while (otherTail->next != other.head) {
        otherTail = otherTail->next;
    }

    tail->next = other.head;

    otherTail->next = head;

    other.head = NULL;
}

#endif