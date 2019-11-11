/*
 *	2019.6.28
 *	data structure implementation - stack_singlyLinkedList
 */
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }

    ~Node() {
        Node *temp = next;
        if (temp->next != NULL)
            next = next->next;
        temp = NULL;
    }

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class StackSLL {
public:
    int s_size;
    Node *head;

    StackSLL() {
        s_size = 0;
        head = NULL;
    }

    ~StackSLL() {
        Node *temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
        }
        head = NULL;
    }

    void push(int value) {
        Node *new_node = new Node(value);
        if (head == NULL)
            head = new_node;
        else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        s_size++;
    }

    int top() {
        if (head == NULL)
            return -1;
        else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            return temp->data;
        }
    }

    void pop() {
        if (head == NULL)
            return;
        else {
            Node *cur = head;
            Node *temp = head;
            while (cur->next != NULL) {
                temp = cur;
                cur = cur->next;
            }
            temp->next = NULL;
            s_size--;
        }
    }

    int size() {
        return s_size;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {

    StackSLL teacher;
    Node A;

    teacher.head = &A;

    Node B;
    A.next = &B;

    Node C;
    B.next = &C;

    int arr[10] = {1, 2, 3, 4};
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << endl;
    }

    *(arr + 4) = 10;
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << endl;
    }

    cout << "GOOD?";

    return 0;
}