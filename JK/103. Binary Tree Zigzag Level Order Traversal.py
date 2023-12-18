# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def zigzagLevelOrder(root):
    if not root:
        return []
    
    results = []
    queue = [root]
    l_to_r = True

    while queue:
        level_size = len(queue)
        level = []

        for _ in range(level_size):
            node = queue.pop(0)
            if l_to_r:
                level.append(node.val)
            else:
                level.insert(0, node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        results.append(level)
        l_to_r = not l_to_r

    return results