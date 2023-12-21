# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        flag=False
        if not root:
            return flag
        return self.checkSm(0,targetSum, flag, root)
    
    def checkSm(self, sm, targetSum, flag, node):
        smValue=sm+node.val
        if not node.left and not node.right:
            if smValue==targetSum:
                flag=True
                return flag
            else:
                return flag
        if flag:
            return flag
        else:
            if node.left:
                leftFlag=self.checkSm(smValue,targetSum, flag, node.left)
                if leftFlag:
                    return leftFlag
            if node.right:
                rightFlag=self.checkSm(smValue,targetSum, flag, node.right)
                if rightFlag:
                    return rightFlag
        return flag