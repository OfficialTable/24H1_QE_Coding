# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        # DFS to count nodes
        count = 1  # Count the current node
        count += self.countNodes(root.left)  # Count nodes in the left subtree
        count += self.countNodes(root.right)  # Count nodes in the right subtree

        return count


#-----------------------------아래는 DFS 아닌 방식 ---------------------------#

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        left_depth = self.getDepth(root.left)
        right_depth = self.getDepth(root.right)

        # 양쪽 깊이가 같을 때, tree는 full & 노드의 수는 2^(left_depth) - 1
        if left_depth == right_depth:
            return 2**left_depth + self.countNodes(root.right)
        else:
            return 2**right_depth + self.countNodes(root.left)

    def getDepth(self, node):
        depth = 0
        while node:
            depth += 1
            node = node.left
        return depth