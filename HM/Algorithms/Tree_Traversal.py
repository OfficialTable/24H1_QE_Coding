# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

################algorithms (pre, in, post, level-order Traversal)#############
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

def levelorderTraversal(root):
    if not root:
        return []

    result = []
    queue = [root]

    while queue:
        level_size = len(queue)
        current_level = []

        for _ in range(level_size):
            node = queue.pop(0)
            current_level.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(current_level)

    return result


if __name__ == "__main__":
    # Create a sample tree: [3,9,20,null,null,15,7]
    #     3
    #    / \
    #   9  20
    #      / \
    #     15  7
    tree = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))

    # Perform traversals
    pre_result = preorderTraversal(tree)
    in_result = inorderTraversal(tree)
    post_result = postorderTraversal(tree)
    level_result = levelorderTraversal(tree)

    # Print results
    print("0) Preorder Traversal:", pre_result, ", Inorder Traversal:", in_result, ", Postorder Traversal:", post_result, ", Levelorder Traversal:", level_result)
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
    level_result_example1 = levelorderTraversal(tree_example1)
    print("1) Preorder Traversal: ", pre_result_example1, ", Inorder Traversal: ", in_result_example1, ", Postorder Traversal: ", post_result_example1, ", Levelorder Traversal: ", level_result_example1)
# Example 2:
# Input: root = []
# Output: []
if __name__ == "__main__":
    tree_example2 = None  # Empty tree
    pre_result_example2 = preorderTraversal(tree_example2)
    in_result_example2 = inorderTraversal(tree_example2)
    post_result_example2 = postorderTraversal(tree_example2)
    level_result_example2 = levelorderTraversal(tree_example2)
    print("2) Preorder Traversal: ", pre_result_example2, ", Inorder Traversal: ", in_result_example2, ", Postorder Traversal: ", post_result_example2, ", Levelorder Traversal: ", level_result_example2)

# Example 3:
# Input: root = [1]
# Output: [1]
if __name__ == "__main__":
    tree_example3 = TreeNode(1)
    pre_result_example3 = preorderTraversal(tree_example3)
    in_result_example3 = inorderTraversal(tree_example3)
    post_result_example3 = postorderTraversal(tree_example3)
    level_result_example3 = levelorderTraversal(tree_example3)
    print("3) Preorder Traversal: ", pre_result_example3, ", Inorder Traversal: ", in_result_example3, ", Postorder Traversal: ", post_result_example3, ", Levelorder Traversal: ", level_result_example3)
