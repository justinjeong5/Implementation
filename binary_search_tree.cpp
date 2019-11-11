/*
 * binary_search_tree
 */

#include <iostream>

using namespace std;

struct Node {
    int item = -1;
    Node *parent = NULL;
    Node *left = NULL;
    Node *right = NULL;

    Node(int data) : item(data) {}
};

class Tree {
private:
    Node *root = NULL;
    int cnt = 0;
public:
    Tree() {}

    Node *search(Node *node, int data) {
        if (node == NULL || node->item == data)
            return node;
        if (node->item > data)
            return search(node->left, data);
        return search(node->right, data);
    }

    void transplant(Node *parent, Node *child) {
        if (parent->parent == NULL) {
            root = child;
        } else if (parent->parent->left == parent) {
            parent->parent->left = child;
        } else parent->parent->right = child;

        if (child != NULL) {
            child->parent = parent->parent;
        }
    }

    void insert(int data) {
        Node *newNode = new Node(data);
        Node *cur = root;
        Node *parent = NULL;
        while (cur != NULL) {
            parent = cur;
            if (cur->item > newNode->item) {
                cur = cur->left;
            } else cur = cur->right;
        }
        newNode->parent = parent;
        if (parent == NULL) {
            root = newNode;
            return;
        }

        if (parent->item > newNode->item) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void remove(int data) {
        Node *node = search(root, data);
        if (node->left == NULL && node->right == NULL) {
            if (node->parent == NULL) {
                root = NULL;
            } else if (node->parent->left == node) {
                node->parent->left = NULL;
            } else node->parent->right = NULL;
        } else if (node->left != NULL && node->right == NULL) {
            transplant(node, node->left);
        } else if (node->left == NULL && node->right != NULL) {
            transplant(node, node->right);
        } else {
            Node *min = node->right;
            while (min->left != NULL) {
                min = min->left;
                cnt++;
            }
            if (min->parent != node) {
                transplant(min, min->right);
                min->right = node->right;
                min->right->parent = min;
            }
            transplant(node, min);
            min->left = node->left;
            min->left->parent = min;
        }
        cout << cnt << endl;
    }
};

int main() {
    Tree tree;
    int N, M, input;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input;
        tree.insert(input);
    }

    for (int i = 0; i < M; i++) {
        cin >> input;
        tree.remove(input);
    }


    return 0;
}