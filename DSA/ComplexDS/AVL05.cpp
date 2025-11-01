#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1; // new node is initially at height 1
    }
};

// get height of a node
int getHeight(Node* n) {
    return n ? n->height : 0;
}

// get balance factor
int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

// right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

// left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// insert node into AVL
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    else return root; // duplicate keys not allowed

    // update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // 4 rotation cases
    if (balance > 1 && key < root->left->data) return rotateRight(root);          // Left-Left
    if (balance < -1 && key > root->right->data) return rotateLeft(root);         // Right-Right
    if (balance > 1 && key > root->left->data) {                                  // Left-Right
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && key < root->right->data) {                                // Right-Left
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// simple inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int values[] = {10, 20, 30, 40, 50, 25};

    for (int val : values)
        root = insert(root, val);

    cout << "Inorder (Balanced AVL): ";
    inorder(root);
    cout << endl;

    return 0;
}
