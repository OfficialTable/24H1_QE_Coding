'''
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    @classmethod
    def addList(cls, lst):
        if not lst:
            return None

        head = ListNode(lst[0])
        current = head

        for val in lst[1:]:
            current.next = ListNode(val)
            current = current.next

        return head

    def reset(self):
        self.val = 0
        self.next = None



def isPalindrome(head: ListNode) -> bool:
    # 0. edge case (empty list or one node list)
    if not head or not head.next:
        return True
    
    # 1. find the middle node
    nor = rev = head
    while rev and rev.next:
        nor = nor.next
        rev = rev.next.next
    # 2. reverse the second half
    pre = None
    while nor:
        temp = nor.next
        nor.next = pre
        pre = nor
        nor = temp
    # 3. compare the first half and the second half
    while pre:
        if pre.val != head.val:
            return False
        pre = pre.next
        head = head.next
    return True

def PrintLinkedList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
        if head.next is None:
            print(head.val)
            break
    print("\n")

if __name__ == "__main__":

    print("234_PalindromeLinkedList.py")
    print("\nCase 1")

    input_list = [1,2,2,1]
    nums = ListNode.addList(input_list)
    PrintLinkedList(nums)
    ans = True
    res = isPalindrome(head=nums)
    print(res, "\n==> check: ", res==ans)
    nums.reset()


    print("\nCase 2")
    input_list = [1,2]
    nums = ListNode.addList(input_list)
    PrintLinkedList(nums)
    ans = False
    res = isPalindrome(head=nums)
    print(res, "\n==> check: ", res==ans)
    nums.reset()


    print("\nCase 3")
    input_list = [1,2,3,2,1]
    nums = ListNode.addList(input_list)
    PrintLinkedList(nums)
    ans = True
    res = isPalindrome(head=nums)
    print(res, "\n==> check: ", res==ans)
    nums.reset()


    print("\nCase 4")
    input_list = [1,2,3,4,2,1]
    nums = ListNode.addList(input_list)
    PrintLinkedList(nums)
    ans = True
    res = isPalindrome(head=nums)
    print(res, "\n==> check: ", res==ans)
    nums.reset()
