class TreeNode:
    def __init__(self, value):
        # Each node stores a value
        self.val = value
        
        # Pointers to left and right child nodes
        self.left = None
        self.right = None
def inorder_traversal(root):
    """
    Inorder traversal visits:
    left subtree -> current node -> right subtree
    
    This traversal is especially important because:
    - In a Binary Search Tree, it gives sorted order
    """
    
    # Base case: empty node means nothing to process
    if root is None:
        return
    
    # Step 1: go as left as possible
    inorder_traversal(root.left)
    
    # Step 2: process current node
    print(root.val, end=" ")
    
    # Step 3: visit right subtree
    inorder_traversal(root.right)
def preorder_traversal(root):
    """
    Preorder traversal visits:
    current node -> left subtree -> right subtree
    
    Commonly used when:
    - copying a tree
    - serializing a tree structure
    """
    
    if root is None:
        return
    
    # Process the current node first
    print(root.val, end=" ")
    
    # Then explore left and right subtrees
    preorder_traversal(root.left)
    preorder_traversal(root.right)

    def postorder_traversal(root):
    """
    Postorder traversal visits:
    left subtree -> right subtree -> current node
    
    Used when:
    - deleting a tree
    - evaluating expression trees
    """
    
    if root is None:
        return
    
    postorder_traversal(root.left)
    postorder_traversal(root.right)
    
    # Process node after children are done
    print(root.val, end=" ")
