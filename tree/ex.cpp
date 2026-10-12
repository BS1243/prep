#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// 전위 순회: Root -> Left -> Right
void preorder(Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// 중위 순회: Left -> Root -> Right
void inorder(Node* node) {
    if (node == nullptr)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// 후위 순회: Left -> Right -> Root
void postorder(Node* node) {
    if (node == nullptr)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preorder(root);
    cout << endl;

    cout << "중위 순회: ";
    inorder(root);
    cout << endl;

    cout << "후위 순회: ";
    postorder(root);
    cout << endl;

    return 0;
}