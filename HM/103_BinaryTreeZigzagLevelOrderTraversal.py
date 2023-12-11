class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def zigzagLevelOrder(self, root):
        if root is None:
            return []

        result = []
        queue = [(root, 0)]  # Tuple of (node, level)
        level_dict = {}

        while queue:
            node, level = queue.pop(0)

            if level not in level_dict:
                level_dict[level] = []
            
            level_dict[level].append(node.val)

            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))

        for level, nodes in level_dict.items():
            if level % 2 == 1:  # If level is odd, reverse the order
                nodes = nodes[::-1]
            result.append(nodes)

        return result

# Example usage:
if __name__ == "__main__":
    # Example 1:
    # Input: root = [3,9,20,null,null,15,7]
    # Output: [[3],[20,9],[15,7]]
    tree_example1 = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
    solution = Solution()
    result_example1 = solution.zigzagLevelOrder(tree_example1)
    print(result_example1)

    # Example 2:
    # Input: root = [1]
    # Output: [[1]]
    tree_example2 = TreeNode(1)
    result_example2 = solution.zigzagLevelOrder(tree_example2)
    print(result_example2)

    # Example 3:
    # Input: root = []
    # Output: []
    tree_example3 = None  # Empty tree
    result_example3 = solution.zigzagLevelOrder(tree_example3)
    print(result_example3)
