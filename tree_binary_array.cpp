/*
 * tree_binary_array
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *parent = NULL;
    vector<Node *> children = {};
    int item;

    Node(int a) : item(a), parent(NULL) {}

    void insertChild(Node *data) {
        children.push_back(data);
    }

    void setParent(Node *node) {
        this->parent = node;
    }
};

class Tree {
private:
    Node *root = NULL;
    vector<Node *> nodeList = {};
    int size = 0;
public:
    Tree(int a) {
        Node *newNode = new Node(a);
        root = newNode;
        nodeList.push_back(newNode);
        size++;
    }

    void insert(int parent, int data);

    void show(int a);

    void showDepth(int a);
};

void Tree::insert(int parentData, int data) {
    for (int i = 0; i < nodeList.size(); i++) {
        Node *parent;
        Node *newNode = new Node(data);
        if (nodeList[i]->item == parentData) {
            parent = nodeList[i];
            parent->insertChild(newNode);
            newNode->setParent(parent);
            nodeList.push_back(newNode);
            size++;
            break;
        }
    }
}

void Tree::show(int a) {
    for (int i = 0; i < (int) nodeList.size(); i++) {
        if (nodeList[i]->item == a) {
            if (nodeList[i]->children.size() == 0) {
                cout << 0 << endl;
                return;
            }
            for (int j = 0; j < nodeList[i]->children.size(); j++) {
                cout << nodeList[i]->children[j]->item << " ";
            }
            cout << endl;
            return;
        }
    }
}

void Tree::showDepth(int a) {
    int depth = 0;
    for (int i = 0; i < nodeList.size(); i++) {
        if (nodeList[i]->item == a) {
            Node *temp = nodeList[i];
            while (true) {
                if (temp->parent == NULL) {
                    cout << depth << endl;
                    return;
                } else {
                    temp = temp->parent;
                    depth++;
                }
            }
        }
    }
}


int main() {
    Tree tree(1);

    int node, question;
    cin >> node >> question;
    for (int i = 0; i < node; i++) {
        int parent;
        cin >> parent;
        while (true) {
            int a;
            cin >> a;
            if (a == 0) {
                break;
            } else {
                tree.insert(parent, a);
            }
        }
    }

    //for (int i = 0; i < question; i++)
    //{
    //	int c;
    //	cin >> c;
    //	tree.show(c);
    //}

    for (int i = 0; i < question; i++) {
        int c;
        cin >> c;
        tree.showDepth(c);
    }


    system("pause");
    return 0;
}