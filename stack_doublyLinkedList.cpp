/*
 *	2019.6.28
 *	data structure implementation - stack_doublyLinkedList
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
        next->pre = pre;
        pre->next = next;
        next = NULL;
        pre = NULL;
    }

    Node(int value) {
        data = value;
        next = NULL;
        pre = NULL;
    }
};

class StackDLL {
public:
    int s_size;
    Node *header;
    Node *trailer;

    StackDLL() {
        s_size = 0;
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->pre = header;
    }

    ~StackDLL() {
        Node *temp;
        while (header->next != trailer) {
            temp = header->next;
            header = temp->next;
            temp->next->pre = header;
            delete temp;
        }
    }

    void push(int value) {
        Node *new_node = new Node(value);
        if (header->next == trailer) {
            header->next = new_node;
            new_node->pre = header;
            trailer->pre = new_node;
            new_node->next = trailer;
        } else {
            trailer->pre->next = new_node;
            new_node->pre = trailer->pre;
            new_node->next = trailer;
            trailer->pre = new_node;
        }
        s_size++;
    }

    int top() {
        if (trailer->pre == trailer) return -1;
        return trailer->pre->data;
    }

    void pop() {
        if (trailer->pre == header) return;
        Node *temp = trailer->pre->pre;
        delete trailer->pre;
        temp->next = trailer;
        trailer->pre = temp;
        s_size--;
    }

    int size() {
        return s_size;
    }

    bool empty() {
        return s_size == 0;
    }

    void clear() {
        Node *temp;
        while (header->next != trailer) {
            temp = header->next;
            header = temp->next;
            temp->next->pre = header;
            delete temp;
        }
    }
};