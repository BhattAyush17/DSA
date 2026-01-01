#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Create a node with given value
    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(TreeNode* root) {
    // Left -> Root -> Right
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root) {
    // Root -> Left -> Right
    if (root == nullptr) return;

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root) {
    // Left -> Right -> Root
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

void levelOrderTraversal(TreeNode* root) {
    // Traverses tree level by level
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int height(TreeNode* root) {
    // Returns height of the tree
    if (root == nullptr) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int countNodes(TreeNode* root) {
    // Counts total number of nodes
    if (root == nullptr) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(TreeNode* root) {
    // Counts nodes with no children
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

bool search(TreeNode* root, int key) {
    // Searches a value in the tree
    if (root == nullptr) return false;

    if (root->val == key) return true;

    return search(root->left, key) || search(root->right, key);
}

void deleteTree(TreeNode* root) {
    // Frees all allocated memory
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder: ";
    postorderTraversal(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "Height: " << height(root) << endl;
    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Leaf Nodes: " << countLeafNodes(root) << endl;

    int key = 5;
    cout << "Search " << key << ": ";
    cout << (search(root, key) ? "Found" : "Not Found") << endl;

    deleteTree(root);
    root = nullptr;

    return 0;
}
