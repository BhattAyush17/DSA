#include <iostream>
#include <cmath>
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

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

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
    while (root->left != nullptr) root = root->left;
    return root->data;
}

// Find maximum value in BST
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    while (root->right != nullptr) root = root->right;
    return root->data;
}


// Calculate height of tree
int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}


int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// "Resonate" function — gives a structural summary of BST
void resonate(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty. Nothing to resonate." << endl;
        return;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int balance = leftHeight - rightHeight;
    int totalNodes = countNodes(root);

    cout << "\n--- BST Resonance Report ---\n";
    cout << "Total Nodes      : " << totalNodes << endl;
    cout << "Tree Height      : " << height(root) << endl;
    cout << "Left Subtree Ht  : " << leftHeight << endl;
    cout << "Right Subtree Ht : " << rightHeight << endl;
    cout << "Balance Factor   : " << balance << " ("
         << (abs(balance) <= 1 ? "Balanced" : "Unbalanced") << ")" << endl;
    cout << "Structural Resonance Complete.\n";
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

    cout << "Inorder Traversal of the BST (Sorted Order): ";
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

    
    resonate(root);

    return 0;
}
#include <iostream>
#include <cmath>
#include <queue>
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
    if (root == nullptr) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search for a value in BST
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}

// Find minimum value
int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

// Find maximum value
int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
}

// Height of tree
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Count nodes
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// NEW: Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    cout << "\nLevel Order Traversal: ";
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

// NEW: Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child or one child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 2: Two children
        root->data = findMin(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

// ✅ NEW: Check if BST is height-balanced
bool isBalanced(Node* root) {
    if (!root) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

// ✅ NEW: Lowest Common Ancestor (LCA)
Node* LCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    return root;
}

// "Resonate" function — summary
void resonate(Node* root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int balance = leftHeight - rightHeight;
    int totalNodes = countNodes(root);

    cout << "\n--- BST Resonance Report ---\n";
    cout << "Total Nodes      : " << totalNodes << endl;
    cout << "Tree Height      : " << height(root) << endl;
    cout << "Left Subtree Ht  : " << leftHeight << endl;
    cout << "Right Subtree Ht : " << rightHeight << endl;
    cout << "Balance Factor   : " << balance
         << " (" << (abs(balance) <= 1 ? "Balanced" : "Unbalanced") << ")\n";
    cout << "Balanced (Full Check): "
         << (isBalanced(root) ? " Yes" : " No") << endl;
    cout << "Structural Resonance  Complete.\n";
}

int main() {
    Node* root = nullptr;

    // Insert elements
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal (Sorted): ";
    inorder(root);
    cout << endl;

    levelOrder(root);

    int key = 60;
    cout << "\nSearching for " << key << ": "
         << (search(root, key) ? "Found " : "Not Found ") << endl;

    cout << "Minimum Value: " << findMin(root) << endl;
    cout << "Maximum Value: " << findMax(root) << endl;

    resonate(root);

    // Delete a node
    cout << "\nDeleting 70 from BST..." << endl;
    root = deleteNode(root, 70);
    inorder(root);
    cout << endl;

    // Find LCA
    Node* lca = LCA(root, 20, 40);
    cout << "\nLCA of 20 and 40: " << (lca ? to_string(lca->data) : "None") << endl;

    return 0;
}
