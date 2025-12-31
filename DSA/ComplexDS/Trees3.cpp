#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;                 // Value stored in the node
    TreeNode* left;          // Pointer to left child
    TreeNode* right;         // Pointer to right child

    // Constructor initializes node with value and null children
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(TreeNode* root) {
    /*
        Inorder traversal logic:
        1. Visit left subtree
        2. Process current node
        3. Visit right subtree

        In a Binary Search Tree, this traversal
        prints elements in sorted order.
    */

    // Base case: if node doesn't exist, return
    if (root == nullptr) {
        return;
    }

    // Step 1: Go to left subtree
    inorderTraversal(root->left);

    // Step 2: Process current node
    cout << root->val << " ";

    // Step 3: Go to right subtree
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root) {
    /*
        Preorder traversal logic:
        1. Process current node
        2. Visit left subtree
        3. Visit right subtree

        Useful for:
        - Copying a tree
        - Storing tree structure
    */

    if (root == nullptr) {
        return;
    }

    // Process node before children
    cout << root->val << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(TreeNode* root) {
    /*
        Postorder traversal logic:
        1. Visit left subtree
        2. Visit right subtree
        3. Process current node

        Commonly used for:
        - Deleting a tree
        - Expression tree evaluation
    */

    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);

    // Process node after its children
    cout << root->val << " ";
}
int main() {
    // Manually building the tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
