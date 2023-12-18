# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def maxDepth(root):
    if not root:
        return 0

    queue = [root]
    ans = 0

    while queue:
        level_size = len(queue)
        for i in range(level_size):
            node = queue.pop(0)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        ans += 1

    return ans