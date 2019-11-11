/*
 *	2019.1.7
 *	data structure implementation heap_doublyLinkedList
 */
#include <iostream>
#include <vector>

#define ROOT_INDEX 1

using namespace std;

struct Node {
    Node *prev;
    Node *next;
    int item;

    Node(int a) : item(a), prev(NULL), next(NULL) {}
};

class Heap {
private:
    Node *header;
    Node *trailer;
    vector<Node *> v;
    int heap_sz;
public:
    Heap() {
        header = new Node(NULL);
        trailer = new Node(NULL);
        header->next = trailer;
        trailer->prev = header;
        v = {};
        v.push_back(header);
        heap_sz = 0;
    }

    void _swap(int index1, int index2) {
        v[0]->item = v[index1]->item;
        v[index1]->item = v[index2]->item;
        v[index2]->item = v[0]->item;
    }

    void Upheap(int index) {
        int parent = index / 2;
        if (parent == 0) return;
        else {
            if (v[parent]->item > v[index]->item) {
                _swap(parent, index);
                Upheap(parent);
            } else return;
        }
    }

    void Downheap(int index) {
        int left = index * 2;
        int right = index * 2 + 1;

        if (right <= heap_sz) {
            if (v[index]->item > v[left]->item && v[index]->item > v[right]->item) {
                if (v[left]->item > v[right]->item) {
                    _swap(right, index);
                    Downheap(right);
                } else if (v[left]->item < v[right]->item) {
                    _swap(left, index);
                    Downheap(left);
                } else return;
            } else if (v[index]->item > v[left]->item) {
                _swap(index, left);
                Downheap(left);
            } else if (v[index]->item > v[right]->item) {
                _swap(index, right);
                Downheap(right);
            } else return;
        } else if (left <= heap_sz) {
            if (v[left]->item < v[index]->item) {
                _swap(index, left);
                Downheap(left);
            } else return;
        }
    }

    void insert(int data) {
        Node *newNode = new Node(data);
        newNode->next = trailer;
        newNode->prev = trailer->prev;
        trailer->prev->next = newNode;
        trailer->prev = newNode;

        v.push_back(newNode);
        heap_sz++;
        Upheap(heap_sz);
    }

    int remove() {
        int ref = v[ROOT_INDEX]->item;
        v[ROOT_INDEX] = v[heap_sz];
        heap_sz--;
        v.pop_back();
        Downheap(ROOT_INDEX);
        return ref;
    }

    int removeList() {
        int ref = header->next->item;
        Node *temp = trailer->prev;
        trailer->prev = trailer->prev->prev;
        trailer->prev->next = trailer;

        header->next->item = temp->item;
        v.pop_back();
        delete temp;
        heap_sz--;
        Downheap(ROOT_INDEX);
        return ref;
    }

    void showHeap() {
        for (int i = 1; i < (int) v.size(); i++) {
            cout << v.at(i)->item << " ";
        }
        cout << endl;
    }

    void showArrange(int size) {
        for (int i = 1; i < size; i++) {
            cout << remove() << " ";
        }
        cout << endl;
    }

    void showHeapByList() {
        Node *temp = header->next;
        while (true) {
            if (temp->next == trailer) {
                cout << temp->item << endl;
                return;
            } else {
                cout << temp->item << " ";
                temp = temp->next;
            }
        }
    }

    void showArrangeByList() {
        Node *temp = header->next;
        while (true) {
            if (temp->next == trailer) {
                cout << removeList() << endl;
                return;
            } else {
                cout << removeList() << " ";
                temp = header->next;
            }
        }
    }

    vector<Node *> getVec() {
        return this->v;
    }
};

int main() {
    Heap heap;

    int N, input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        heap.insert(input);
    }
    heap.showHeap();
    heap.showHeapByList();

    int size = (int) heap.getVec().size();
    heap.showArrange(size);
    heap.showArrangeByList();

    system("pause");
    return 0;
}