/*
 *	2019.7.4
 *	data structure implementation - deque_array
 */
#include <iostream>

using namespace std;

class DequeArr {
public:
    int dq_size, capacity;
    int *deque;

    DequeArr() {
        dq_size = 0;
        capacity = 8;
        deque = new int[capacity];
    }

    ~DequeArr() {
        delete deque;
        deque = NULL;
    }

    void push_front(int value) {

    }
};