'''
Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.
 
Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

'''

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


## UTILS ##
def list_to_binary_tree(nums):
    if not nums:
        return None

    def build_tree(nums, start, end):
        if start > end:
            return None

        mid = (start + end) // 2
        root = TreeNode(nums[mid])
        root.left = build_tree(nums, start, mid - 1)
        root.right = build_tree(nums, mid + 1, end)

        return root

    return build_tree(nums, 0, len(nums) - 1)

#######

def countNodes(root: TreeNode) -> int:
    if not root:
        return 0

    # Find the height of the leftmost branch
    left_height = 0
    left_node = root
    while left_node:
        left_height += 1
        left_node = left_node.left

    # Find the height of the rightmost branch
    right_height = 0
    right_node = root
    while right_node:
        right_height += 1
        right_node = right_node.right

    # when the left and right heights are equal
    if left_height == right_height:
        return 2 ** left_height - 1
    else:
        # Otherwise, we recursively calculate the left and right subtrees.
        return 1 + countNodes(root.left) + countNodes(root.right)
    
if __name__ == '__main__':
    print("222_CountCompleteTreeNodes.py")
    print("\nCase 1")
    nums = [1,2,3,4,5,6]
    root = list_to_binary_tree(nums)
    res = countNodes(root)
    ans = 6
    print(res, "\n==> check: ", res==ans)

    print("\nCase 2")
    nums = []
    root = list_to_binary_tree(nums)
    res = countNodes(root)
    ans = 0
    print(res, "\n==> check: ", res==ans)

    print("\nCase 3")
    nums = [1]
    root = list_to_binary_tree(nums)
    res = countNodes(root)
    ans = 1
    print(res, "\n==> check: ", res==ans)



