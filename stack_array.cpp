/*
 *   2019.6.28
 *   data structure implementation - stack_array
 */
#include <iostream>

using namespace std;

class StackArr {
public:
    int s_size, capacity;
    int *stack;

    StackArr() {
        s_size = 0;
        capacity = 8;
        stack = new int[capacity];
    }

    ~StackArr() {
        delete[] stack;
        stack = NULL;
    }

    void push(int value) {
        if (s_size == capacity) {
            capacity *= 2;

            int *temp = new int[capacity];
            for (int i = 0; i < capacity / 2; i++) {
                temp[i] = stack[i];
            }
            delete[] stack;
            stack = temp;
        }

        stack[s_size++] = value;
    }

    int top() {
        if (s_size == 0)
            return -1;
        return stack[s_size - 1];
    }

    void pop() {
        if (s_size == 0)
            return;
        s_size--;
    }

    bool empty() {
        return s_size == 0;
    }

    int size() {
        return s_size;
    }

};
