/*
 *	2019.10.14
 *	LeetCode 225. Implement stack_using_queue
 */
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> q_temp;
        int sz = q.size();
        for (int it = 0; it < sz - 1; it++) {
            q_temp.push(q.front());
            q.pop();
        }
        int temp = q.front();
        q.pop();
        sz = q_temp.size();
        for (int it = 0; it < sz; it++) {
            q.push(q_temp.front());
            q_temp.pop();
        }
        return temp;
    }

    /** Get the top element. */
    int top() {
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int ans = obj->pop();
    ans = obj->pop();
    ans = obj->pop();
    bool emp = obj->empty();

    return 0;
}