#include <iostream>
using namespace std;
#define NULL_PTR NULL

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL_PTR;
        right = NULL_PTR;
    }
};

Node* createTree() {
    int val;
    cout << "Enter data (-1 for no node): ";
    cin >> val;

    if (val == -1) 
        return NULL;

    Node* root = new Node(val);
    cout << "Enter left child of " << val << ":\n";
    root->left = createTree();
    cout << "Enter right child of " << val << ":\n";
    root->right = createTree();

    return root;
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int treeHeight(Node* root) {
    if (!root) return 0;
    int leftH = treeHeight(root->left);
    int rightH = treeHeight(root->right);
    return max(leftH, rightH) + 1;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

bool searchNode(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return searchNode(root->left, key) || searchNode(root->right, key);
}

int main() {
    cout << "Create your binary tree manually:\n";
    Node* root = createTree();

    cout << "\nInorder traversal: ";
    printInorder(root);
    cout << "\nPreorder traversal: ";
    printPreorder(root);
    cout << "\nPostorder traversal: ";
    printPostorder(root);

    cout << "\n\nTree height: " << treeHeight(root);
    cout << "\nTotal nodes: " << countNodes(root);
    cout << "\nLeaf nodes: " << countLeafNodes(root);

    int key;
    cout << "\n\nEnter value to search: ";
    cin >> key;
    cout << (searchNode(root, key) ? "Found\n" : "Not Found\n");

    return 0;
}
