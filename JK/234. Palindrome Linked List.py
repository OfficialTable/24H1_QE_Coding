# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head):
        prev = None
        curr = head

        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev   


    def isPalindrome(self, head) -> bool:
        
        cur = head
        tmp = head

        while cur != None and cur.next != None:
            cur = cur.next.next
            tmp = tmp.next

        cur = head
        tmp = self.reverseList(tmp)

        while tmp != None:
            if tmp.val != cur.val:
                return False

            tmp = tmp.next
            cur = cur.next

        return True


# class Solution:
#     def isPalindrome(self, head: Optional[ListNode]) -> bool:
#         stack = []

#         current = head

#         while current:
#             stack.append(current.val)
#             current = current.next

#         current = head
#         while current:
#             top = stack.pop()
#             if current.val != top:
#                 return False
#             current = current.next

#         return True        