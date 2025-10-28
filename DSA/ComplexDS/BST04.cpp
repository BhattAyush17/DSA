#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new value into BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder Traversal Algorithm — (Left, Root, Right)
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search for a value in BST
bool search(Node* root, int key) {
    if (root == nullptr) return false;

    if (root->data == key) return true;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

// Find minimum value in BST
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Find maximum value in BST
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

int main() {
    Node* root = nullptr;

    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal (Sorted Order): ";
    inorder(root);
    cout << endl;

    // Example search
    int key = 60;
    if (search(root, key))
        cout << "Value " << key << " found in BST." << endl;
    else
        cout << "Value " << key << " not found in BST." << endl;

    // Display Min and Max values
    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;

    return 0;
}
