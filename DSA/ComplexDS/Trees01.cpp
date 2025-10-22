// Basic construction of a Binary Tree and implementation of Inorder Traversal
#include <iostream>
using namespace std;

// Step 1: Define a structure for a tree node
struct Node {
    int data;
    Node* left;   // Pointer to left child
    Node* right;  // Pointer to right child

    // Constructor to initialize node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Step 2: Function to perform Inorder Traversal (Left → Root → Right)
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);   // Traverse left subtree
    cout << root->data << " ";      // Visit current node
    inorderTraversal(root->right);  // Traverse right subtree
}




// Step 3: Main function to build and test the tree
int main() {
    // Manually creating the tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    //       / \
    //      6   7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    cout << "Inorder Traversal of Tree: ";
    inorderTraversal(root);
    cout << endl;


    return 0;
}
