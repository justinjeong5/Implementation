/*
 * heap_array
 */
#include <iostream>
#include <vector>

#define ROOT_INDEX 1
using namespace std;

class Heap {
private:
    vector<int> v;
    int heap_sz = 0;

public:
    Heap() {
        v.push_back(-1);
        heap_sz = 0;
    }

    void _swap(int index1, int index2) {
        v[0] = v[index1];
        v[index1] = v[index2];
        v[index2] = v[0];
    }

    void Upheap(int index) {
        int parent = index / 2;
        if (parent == 0) {
            return;
        } else {
            if (v[parent] > v[index]) {
                _swap(index, parent);
                Upheap(parent);
            } else return;
        }
    }

    void Downheap(int index) {
        int left = index * 2;
        int right = index * 2 + 1;
        if (right <= heap_sz) {
            if (v[index] > v[right] && v[index] > v[left]) {
                if (v[right] > v[left]) {
                    _swap(left, index);
                    Downheap(left);
                } else if (v[left] > v[right]) {
                    _swap(right, index);
                    Downheap(right);
                } else return;
            }
        } else if (left <= heap_sz) {
            if (v[index] > v[left]) {
                _swap(left, index);
                Downheap(left);
            } else return;
        } else return;
    }

    void insert(int index) {
        v.push_back(index);
        Upheap(heap_sz);
        heap_sz++;
    }

    int remove() {
        int ref = v[ROOT_INDEX];
        v[ROOT_INDEX] = v[heap_sz];
        heap_sz--;
        v.pop_back();
        Downheap(ROOT_INDEX);
        return ref;
    }

    vector<int> getVec() {
        return this->v;
    }

    void showHeap() {
        for (int i = 1; i < (int) v.size(); i++) {
            cout << v.at(i) << " ";
        }
        cout << endl;
    }

    void showArrange(int size) {
        for (int i = 1; i < size; i++) {
            cout << remove() << " ";
        }
        cout << endl;
    }
};


int main() {
    Heap h;
    int N, input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        h.insert(input);
    }

    h.showHeap();

    int size = (int) h.getVec().size();
    h.showArrange(size);

    system("pause");
    return 0;
}