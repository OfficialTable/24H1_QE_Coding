# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        ans = []

        def DFS(root):
            if not root:
                ans.append("N")
                return

            ans.append(str(root.val))
            DFS(root.left)
            DFS(root.right)

        DFS(root)
        return ",".join(ans)        
        

    def deserialize(self, data):
        value = data.split(",")
        self.index = 0

        def DFS():
            if value[self.index] == "N":
                self.index += 1
                return None

            root = TreeNode(int(value[self.index]))
            self.index += 1
            root.left = DFS()
            root.right = DFS()
            return root

        return DFS()                