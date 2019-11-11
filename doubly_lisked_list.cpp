/*
 * doubly_lisked_list
 */

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int item;
    Node *next;
    Node *prev;

    Node() : item(NULL), next(NULL), prev(NULL) {}

    Node(int a) : item(a), next(NULL), prev(NULL) {}
};

class List {
private:
    Node *header = NULL;
    Node *trailer = NULL;
    int cnt = -1;
public:
    List() : header(), trailer(), cnt(-1) {
        header = new Node(NULL);
        trailer = new Node(NULL);
        header->next = trailer;
        trailer->prev = header;
    }

    void insertFront(int a);

    void insertBack(int a);

    void removeFront();

    void removeBack();

    void front();

    void back();

    void size();

    void empty();
};

void List::insertFront(int a) {
    Node *newNode = new Node(a);
    header->next->prev = newNode;
    newNode->next = header->next;
    header->next = newNode;
    newNode->prev = header;
    cnt++;
}

void List::insertBack(int a) {
    Node *newNode = new Node(a);
    trailer->prev->next = newNode;
    newNode->prev = trailer->prev;
    trailer->prev = newNode;
    newNode->next = trailer;
    cnt++;
}

void List::removeFront() {
    if (header->next == trailer) {
        cout << -1 << endl;
    } else {
        Node *temp = header->next;
        header->next = header->next->next;
        header->next->prev = header;
        delete temp;
        cnt--;
    }
}

void List::removeBack() {
    if (header->next == trailer) {
        cout << -1 << endl;
    } else {
        Node *temp = trailer->prev;
        trailer->prev = trailer->prev->prev;
        trailer->prev->next = trailer;
        delete temp;
        cnt--;
    }
}

void List::front() {
    if (header->next == trailer) {
        cout << -1 << endl;
    } else {
        cout << header->next->item << endl;
    }
}

void List::back() {
    if (header->next == trailer) {
        cout << -1 << endl;
    } else {
        cout << trailer->prev->item << endl;
    }
}

void List::size() {
    cout << cnt + 1 << endl;
}

void List::empty() {
    if (cnt == -1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    List list;

    int a;
    cin >> a;

    string input;
    for (int i = 0; i < a; i++) {
        cin >> input;
        if (input == "insertFront") {
            int b;
            cin >> b;
            list.insertFront(b);
        } else if (input == "insertBack") {
            int b;
            cin >> b;
            list.insertBack(b);
        } else if (input == "removeFront") {
            list.removeFront();
        } else if (input == "removeBack") {
            list.removeBack();
        } else if (input == "front") {
            list.front();
        } else if (input == "back") {
            list.back();
        } else if (input == "size") {
            list.size();
        } else if (input == "empty") {
            list.empty();
        }

    }

    system("pause");
    return 0;
}