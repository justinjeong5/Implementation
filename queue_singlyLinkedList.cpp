/*
 *	2019.7.4
 *	data structure implementation - queue_singlyLinkedList
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
    int q_size;
    Node *head;

    QueueSLL() {
        q_size = 0;
        head = NULL;
    }

    ~QueueSLL() {
        Node *temp = head;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int value) {
        Node *new_node = new Node(value);
        if (head == NULL)
            head = new_node;
        else {
            Node *temp = head;
            while (temp != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
        q_size++;
    }

    int front() {
        if (head == NULL)
            return -1;
        else return head->data;
    }

    int back() {
        if (head == NULL)
            return -1;
        else {
            Node *temp = head;
            Node *cur = head;
            while (temp != NULL) {
                cur = temp;
                temp = temp->next;
            }
            return cur->data;
        }
    }

    void pop() {
        if (head == NULL)
            return;
        else {
            Node *temp = head->next;
            delete head;
            head = temp;
            q_size--;
        }
    }

    int size() {
        return q_size;
    }

    bool empty() {
        return !q_size;
    }

    void clear() {
        if (head == NULL)
            return;
        else {
            Node *temp = head;
            Node *cur = head;
            while (temp != NULL) {
                cur = temp;
                temp = temp->next;
                delete cur;
            }
        }
    }
};