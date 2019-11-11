/*
 *	2019.6.28
 *	data structure implementation - queue_array
 */
#include <iostream>

using namespace std;

class QueueArr {
public:
    int q_size, capacity;
    int *queue;

    QueueArr() {
        q_size = 0;
        capacity = 8;
        queue = new int[capacity];
    }

    ~QueueArr() {
        delete[] queue;
        queue = NULL;
    }

    void push(int value) {
        if (q_size == capacity) {
            capacity *= 2;
            int *temp = new int[capacity];

            for (int i = 0; i < capacity / 2; i++) {
                temp[i] = queue[i];
            }
            temp = queue;
            delete[] queue;
            queue = NULL;
        }
        queue[q_size++] = value;
    }

    int front() {
        if (q_size == 0) return -1;
        return queue[q_size - 1];
    }

    void pop() {
        if (q_size == 0) return;
        q_size--;
    }

    bool empty() {
        return !q_size;
    }

    int size() {
        return q_size;
    }
};

int main() {
    int input;
    cin >> input;

    int *arr = new int[input];
    for (int i = 0; i < input; i++) {
        cin >> arr[i];
    }


}