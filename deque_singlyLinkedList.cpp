/*
 *	2019.7.4
 *	data structure implementation - deque_singlyLinkedList
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
        next = NULL;
    }

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class QueueSLL {
public:
    int dq_size;
    Node *head;

    QueueSLL() {
        dq_size = 0;
        head = NULL;
    }

    ~QueueSLL() {
        Node *temp = head;
        Node *cur = head;
        while (temp != NULL) {
            cur = temp;
            temp = temp->next;
            delete cur;
        }
        head = NULL;
    }

    void push_front(int value) {
        Node *new_node = new Node(value);
        if (head == NULL)
            head = new_node;
        else {
            Node *temp = head->next;
            head = new_node;
            new_node->next = temp;
        }
        dq_size++;
    }

    void push_back(int value) {
        Node *new_node = new Node(value);
        if (head == NULL)
            head = new_node;
        else {
            Node *temp = head;
            while (temp != NULL)
                temp = temp->next;
            temp = new_node;
        }
        dq_size++;
    }

    void pop_front() {
        if (head == NULL)
            return;
        else {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
        dq_size--;
    }

    void pop_back() {
        if (head == NULL) return;
        Node *temp = head;
        Node *cur = head;
        while (temp != NULL) {
            cur = temp;
            temp = temp->next;
        }
        delete cur;
        dq_size--;
    }

    int front() {
        if (head == NULL) return -1;
        return head->data;
    }

    int back() {
        if (head == NULL) return -1;
        Node *temp = head;
        Node *cur = head;
        while (temp != NULL) {
            cur = temp;
            temp = temp->next;
        }
        return cur->data;
    }

    int size() {
        return dq_size;
    }

    bool empty() {
        return !dq_size;
    }

};