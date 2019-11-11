/*
 *	2019.7.4
 *	data structure implementation - queue_doublyLinkedList
 */
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *pre;

    Node() {
        data = 0;
        next = NULL;
        pre = NULL;
    }

    ~Node() {
        next = NULL;
        pre = NULL;
    }

    Node(int value) {
        data = value;
        next = NULL;
        pre = NULL;
    }
};

class QueueDLL {
public:
    int q_size;
    Node *header;
    Node *trailer;

    QueueDLL() {
        q_size = 0;
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->pre = header;
    }

    ~QueueDLL() {
        if (header->next != trailer) {
            delete header;
            header = NULL;
            delete trailer;
            trailer = NULL;
        } else {
            Node *temp;
            while (header->next != trailer) {
                temp = header->next;
                temp->next->pre = header;
                header->next = temp;
                delete temp;
            }
            header = NULL;
            trailer = NULL;
        }
    }

    void push(int value) {
        Node *new_node = new Node(value);
        header->next->pre = new_node;
        new_node->next = header->next;

        header->next = new_node;
        new_node->pre = header;
        q_size++;
    }

    void pop() {
        if (header->next == trailer) return;
        Node *temp = header->next;
        header->next = temp->next;
        temp->next->pre = header;
        delete temp;
        q_size--;
    }

    void pop_back() {
        if (header->next = trailer) return;
        Node *temp = trailer->pre;
        trailer->pre = temp->pre;
        temp->pre->next = trailer;
        delete temp;
        q_size--;
    }

    int front() {
        if (header->next == trailer) return -1;
        return header->next->data;
    }

    int back() {
        if (header->next == trailer) return -1;
        return trailer->pre->data;
    }

    int size() {
        return q_size;
    }

    bool empty() {
        return !q_size;
    }

};