/*
 * 2019.10.14
 * queue_using_stack
 */
#include <stack>

using namespace std;

class MyQueue {
public:
	stack<int> s;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		stack<int> s_temp;
		while (!s.empty())
		{
			s_temp.push(s.top());
			s.pop();
		}
		int ans = s_temp.top();
		s_temp.pop();
		while (!s_temp.empty())
		{
			s.push(s_temp.top());
			s_temp.pop();
		}
		return ans;
	}

	/** Get the front element. */
	int peek() {
		stack<int> s_temp;
		while (!s.empty())
		{
			s_temp.push(s.top());
			s.pop();
		}
		int ans = s_temp.top();
		s_temp.pop();
		while (!s_temp.empty())
		{
			s.push(s_temp.top());
			s_temp.pop();
		}
		return ans;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {


	return 0;
}