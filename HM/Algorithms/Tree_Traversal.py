# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

################algorithms (pre, in, post-order Traversal)#############
def preorderTraversal(root):
    if root is None:
        return []

    left_list = preorderTraversal(root.left)
    right_list = preorderTraversal(root.right)

    return [root.val] + left_list + right_list

def inorderTraversal(root):
    if root is None:
        return []
    
    left_list = inorderTraversal(root.left)
    right_list = inorderTraversal(root.right)

    return left_list + [root.val] + right_list

def postorderTraversal(root):
    if root is None:
        return []
    
    left_list = postorderTraversal(root.left)
    right_list = postorderTraversal(root.right)

    return left_list + right_list + [root.val]


# Example 1:
# Input: root = [1,null,2,3]
# Create a sample tree: [1, null, 2, 3]
#     1
#      \
#       2
#      /
#     3
# Output: [1,2,3]
if __name__ == "__main__":
    tree_example1 = TreeNode(1, None, TreeNode(2, TreeNode(3)))
    pre_result_example1 = preorderTraversal(tree_example1)
    in_result_example1 = inorderTraversal(tree_example1)
    post_result_example1 = postorderTraversal(tree_example1)
    print("1) Preorder Traversal: ", pre_result_example1, ", Inorder Traversal: ", in_result_example1, ", Postorder Traversal: ", post_result_example1)
# Example 2:
# Input: root = []
# Output: []
if __name__ == "__main__":
    tree_example2 = None  # Empty tree
    result_example2 = preorderTraversal(tree_example2)
    print(result_example2)

# Example 3:
# Input: root = [1]
# Output: [1]
if __name__ == "__main__":
    tree_example3 = TreeNode(1)
    result_example3 = preorderTraversal(tree_example3)
    print(result_example3)
