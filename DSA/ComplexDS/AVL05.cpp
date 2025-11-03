#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Get height safely
inline int getHeight(Node* n) {
    return n ? n->height : 0;
}

// Get balance factor
inline int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

// Utility: update height of a node
inline void updateHeight(Node* n) {
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
}

// Right rotation (LL Case)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights (bottom-up)
    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

// Left rotation (RR Case)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y; // new root
}

// Insert node with balancing
Node* insert(Node* root, int key) {
    // Normal BST insertion
    if (!root)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root; // duplicate key not allowed

    // Update height once after insertion
    updateHeight(root);

    // Check balance factor
    int balance = getBalance(root);

    // --- Rebalance if needed ---
    // LL Case
    if (balance > 1 && key < root->left->data)
        return rotateRight(root);

    // RR Case
    if (balance < -1 && key > root->right->data)
        return rotateLeft(root);

    // LR Case
    if (balance > 1 && key > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    // Balanced — return as is
    return root;
}

// Inorder traversal (sorted order)
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
