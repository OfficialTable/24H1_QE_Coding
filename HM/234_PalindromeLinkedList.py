#class ListNode:
#    def __init__(self, val=0, next=None):
#        self.val = val
#        self.next = next
def isPalindrome(self, head: ListNode) -> bool:
    def reverseList(head: ListNode) -> ListNode:
        prev = None
        curr = head

        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        
        return prev
    
    #Find the midpoint of the linked list
    #slow는 한칸씩, fast는 두칸씩 전진하기 때문에 현재 Slow는 midpoint가 된다.
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    
    start = head

    #이렇게 하면 후반쪽 linked list의 reverse가 만들어지는 셈
    end = reverseList(slow)

    while start and end:
        if start.val == end.val:
            start = start.next
            end = end.next
        else:
            return False

    return True
     