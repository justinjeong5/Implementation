/*
 *	2019.7.4
 *	data structure implementation - queue_circularArray
 */
#include <iostream>
#include <string>

using namespace std;
#define endl '\n'

class QueueCirArr {
public:
    int q_size, capacity;
    int first, last;
    int *queue;

    QueueCirArr() {
        q_size = 0;
        capacity = 8;
        first = 0;
        last = 0;
        queue = new int[capacity];
    }

    ~QueueCirArr() {}

    void push(int value) {
        if (q_size == capacity) {
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i = 0; i < capacity / 2; i++) {
                temp[i] = queue[i];
            }
            queue = temp;
            if (last < first)
                last = first + q_size - 1;
        }
        queue[last] = value;
        last = (last + 1) % (capacity + 1);
        q_size++;
    }

    int front() {
        if (q_size == 0) return -1;
        return queue[first];
    }

    int back() {
        if (q_size == 0) return -1;
        return queue[(last - 1) % (capacity + 1)];
    }

    void pop() {
        if (q_size == 0) return;
        q_size--;
        first = (first + 1) % (capacity + 1);
    }

    bool empty() {
        return !q_size;
    }

    int size() {
        return q_size;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    QueueCirArr queue;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        string input;
        cin >> input;
        if (input == "push") {
            int a;
            cin >> a;
            queue.push(a);
        } else if (input == "pop") {
            if (queue.empty())
                cout << -1 << endl;
            else cout << queue.front() << endl;
            queue.pop();
        } else if (input == "size")
            cout << queue.size() << endl;

        else if (input == "empty") {
            if (queue.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else if (input == "front")
            cout << queue.front() << endl;

        else if (input == "back")
            cout << queue.back() << endl;
    }
    return 0;
}