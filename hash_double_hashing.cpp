/*
 * hash_double_hashing
 */

#include <iostream>

#define DIV1 353333
#define DIV2 17
using namespace std;

struct Item {
    int item;

    Item() {}

    Item(int data) : item(data) {}
};

class Hash {
private:
    int *flag;
    Item *item;
public:
    Hash() {
        flag = new int[DIV1];
        for (int i = 0; i < DIV1; i++) {
            flag[i] = 1;
        }
        item = new Item[DIV1];
    }

    int hash_code1(int key) {
        return key % DIV1;
    }

    int hash_code2(int key) {
        return DIV2 - key % DIV2;
    }

    void insert(int key) {
        int index = hash_code1(key);
        int i = index;
        while (true) {
            if (flag[i] == 1 || flag[i] == -1) {
                item[i] = key;
                flag[i] = 0;
                return;
            }
            i = i + hash_code2(key);
            i = i % DIV1;
            if (i == index) {
                return;
            }
        }
    }

    void search(int key) {
        int index = hash_code1(key);
        int i = index;
        while (true) {
            if (flag[i] == 0 || flag[i] == -1) {
                if (item[i].item == key) {
                    cout << 1 << endl;
                    return;
                }
                i = i + hash_code2(key);
                i = i % DIV1;
                if (i == index) {
                    cout << 0 << endl;
                    return;
                }
            }
            if (flag[i] == 1) {
                cout << 0 << endl;
                return;
            }
        }
    }

    void remove(int key) {
        int index = hash_code1(key);
        int i = index;
        while (true) {
            if (flag[i] == 0 || flag[i] == -1) {
                if (item[i].item == key) {
                    item[i] = -1;
                    flag[i] = -1;
                    return;
                }
                i = i + hash_code2(key);
                i = i % DIV1;
                if (i == index) {
                    cout << 0 << endl;
                    return;
                }
            }
            if (flag[i] == 1) {
                cout << 0 << endl;
                return;
            }
        }
    }
};

int main() {
    Hash hash;
    int N, M, input;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        hash.insert(input);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> input;
        hash.search(input);
    }

    return 0;
}