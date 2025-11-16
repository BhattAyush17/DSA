#include <iostream>
#include <queue>
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

// Traversals
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

// ⭐ NEW: Level-order traversal (Breadth First Search)
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// Height
int treeHeight(Node* root) {
    if (!root) return 0;
    int leftH = treeHeight(root->left);
    int rightH = treeHeight(root->right);
    return max(leftH, rightH) + 1;
}

// Count nodes
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// ⭐ NEW: Count internal (non-leaf) nodes
int countInternalNodes(Node* root) {
    if (!root || (!root->left && !root->right)) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Search
bool searchNode(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return searchNode(root->left, key) || searchNode(root->right, key);
}

// ⭐ NEW: Find max value in the tree
int findMax(Node* root) {
    if (!root) return INT_MIN;
    return max(root->data, max(findMax(root->left), findMax(root->right)));
}

// ⭐ NEW: Mirror the tree
void mirrorTree(Node* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// ⭐ NEW: Delete/free the entire tree
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
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

    cout << "\nLevel-order traversal: ";
    printLevelOrder(root);

    cout << "\n\nTree height: " << treeHeight(root);
    cout << "\nTotal nodes: " << countNodes(root);
    cout << "\nLeaf nodes: " << countLeafNodes(root);
    cout << "\nInternal nodes: " << countInternalNodes(root);
    cout << "\nMaximum value in tree: " << findMax(root);

    int key;
    cout << "\n\nEnter value to search: ";
    cin >> key;
    cout << (searchNode(root, key) ? "Found\n" : "Not Found\n");

    cout << "\nMirroring tree...\n";
    mirrorTree(root);

    cout << "Level-order after mirroring: ";
    printLevelOrder(root);


    
    deleteTree(root);
    cout << "\nTree deleted successfully.\n";

    return 0;
}
