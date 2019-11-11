/*
 * tree_binary_traversal
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int a) : value(a), left(NULL), right(NULL) {}
};

class Tree {
private:
    void recursiveInsert(TreeNode *&, int);

    void recursiveRemove(TreeNode *&, int);

    void preorderRecursivePrint(TreeNode *);

    void postorderRecursivePrint(TreeNode *);

    void inorderRecursivePrint(TreeNode *);

public:
    TreeNode *root;

    Tree() : root(NULL) {}

    void insert(int);

    void remove(int);

    void preorderPrint();

    void postorderPrint();

    void inorderPrint();
};


void Tree::recursiveInsert(TreeNode *&node, int val) {
    if (node == NULL)
        node = new TreeNode(val);   //Ž���ϰ� �ִ� ��尡 NULL�̸� ���� �����(����)

    else if (val > node->value)
        recursiveInsert(node->right, val);   //������ ���� ����� ������ ũ�� ������ Child�� Ž��

    else if (val < node->value)
        recursiveInsert(node->left, val);   //������ ���� ����� ������ ������ ���� Child�� Ž��
}

void Tree::recursiveRemove(TreeNode *&node, int val) {
    TreeNode *removal = new TreeNode(0);

    if (node == NULL)
        return;      //ã�������� ��� �����ؼ� �Լ�����
    else if (val > node->value)
        recursiveRemove(node->right, val);   //������ ���� ����� ������ ũ�� ������ Child�� Ž��
    else if (val < node->value)
        recursiveRemove(node->left, val);   //������ ���� ����� ������ ������ ���� Child�� Ž��

    else //������ ��带 ã����(���� 3���� ���� ������ �ִ�)
    {
        if (node->left == NULL && node->right == NULL) //��� 1: ����� Child�� ������
        {
            delete node;
            node = NULL;
        } else if (node->left == NULL)   //��� 2-1: ����� Child�� ������ �ϳ��� ��
        {
            removal = node;
            node = node->right;
            delete removal;
        } else if (node->right == NULL)   //��� 2-2: ����� Child�� ���� �ϳ��� ��
        {
            removal = node;
            node = node->left;
            delete removal;
        } else                     //��� 3: ����� Child�� �ΰ��� ��
        {
            removal = node->right;
            while (removal->left != NULL)   //����� ������ Subtree���� �ּҰ��� ���� ��带 ã�´�.
                removal = removal->left;

            int minVal = removal->value;   //�ּҰ������ ���� ����صд�.
            recursiveRemove(root, minVal);   //�ּҰ���带 �����Ѵ�
            node->value = minVal;         //����� �ּҰ��� "���� ������ ���� ���� ���"�� ���� �����
        }
    }
}

void Tree::preorderRecursivePrint(TreeNode *node) {
    if (node != NULL) {
        cout << node->value << endl;      //���� ������ node�� ����Ѵ�.
        preorderRecursivePrint(node->left);   //Left Child�� ���������� �ִ��� �������� Ž���Ѵ�.
        preorderRecursivePrint(node->right);//�� ���� Right Child�� Ž���Ѵ�.
    }
}

void Tree::inorderRecursivePrint(TreeNode *node) {
    if (node != NULL) {
        inorderRecursivePrint(node->left); //Left Child�� ���������� �ִ��� �������� Ž���Ѵ�.
        cout << node->value << endl;      //����Ѵ�.
        inorderRecursivePrint(node->right);//�� ���� Right Child�� Ž���Ѵ�.
    }
}

void Tree::postorderRecursivePrint(TreeNode *node) {
    if (node != NULL) {
        postorderRecursivePrint(node->left); //Left Child�� ���������� �ִ��� �������� Ž���Ѵ�.
        postorderRecursivePrint(node->right);//�� ���� Right Child�� Ž���Ѵ�.
        cout << node->value << endl;       //����Ѵ�.
    }
}

///////////////////WRAPPING FUNCTION(�Լ����� main���� ���ϰ� ����Ҽ� �ְ� WRAP���ݴϴ�)//////////////////////

void Tree::insert(int val) {
    recursiveInsert(root, val);
}

void Tree::remove(int val) {
    recursiveRemove(root, val);
}

void Tree::preorderPrint() {
    cout << "PREORDER" << endl;
    preorderRecursivePrint(root);
}

void Tree::inorderPrint() {
    cout << "INORDER" << endl;
    inorderRecursivePrint(root);
}

void Tree::postorderPrint() {
    cout << "POSTORDER" << endl;
    postorderRecursivePrint(root);
}

int main() {


    system("pause");
    return 0;
}