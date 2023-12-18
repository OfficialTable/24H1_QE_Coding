def countNodes(root):
    """
    :type root: TreeNode
    :rtype: int
    """
    def preorderTraversal(root):
        if root is None:
            return []

        left_list = preorderTraversal(root.left)
        right_list = preorderTraversal(root.right)

        return [root.val] + left_list + right_list

    return len(preorderTraversal(root))


#########optimal solution with recursion#############
def countNodes(root):
        if not root:
            return 0

        left = countNodes(root.left)
        right = countNodes(root.right)

        return left + right + 1