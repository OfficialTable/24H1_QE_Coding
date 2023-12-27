class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next
        
def print_list(s:Node)-> None:
    res = []
    cur = s
    while cur:
        res.append(cur.data)
        cur = cur.next
    return res

def palindrome(s:Node)-> int:
    first, cur = s, s
    next = Node(cur.data)
    
    while cur.next:
        cur = cur.next
        tmp = Node(cur.data)
        tmp.next = next
        next = tmp
    while first.next and next.next:
        if first.data != next.data: return 0
        first, next = first.next, next.next
    if first.next or next.next: return 0
    return 1

def sub_list(s:Node, t:Node)->int:
    cur_s = s
    cur_t = t
    same_node = []
    while cur_s:
        if cur_s.data == t.data:
            same_node.append(cur_s)
        cur_s = cur_s.next
    
    flag = 0
    for s_s in same_node:
        s_t = cur_t
        while s_s and s_t:
            if s_s.data != s_t.data: break
            s_s, s_t = s_s.next, s_t.next
        if s_t is None: flag = 1
    
    if flag == 1:
        return 1
    return 0

def max_palindromes(s:Node)->None:
    nodes = []
    cur = s
    while cur:
        nodes.append(cur)
        cur = cur.next
        
    palindromes = []
    length = len(print_list(s))
    
    for sub_len in range(length, 0, -1):
        for start_node in nodes:
            cand = Node(0)
            s_copy = start_node
            cur = cand
            for _ in range(sub_len):
                if not s_copy: break
                new = Node(s_copy.data)
                cur.next = new
                cur = cur.next
                s_copy = s_copy.next
            if palindrome(cand.next):
                is_sub = False
                for prev_pal in palindromes:
                    if sub_list(prev_pal, cand.next):
                        is_sub = True
                        break
                if not is_sub:
                    palindromes.append(cand.next)
                    
    res = []
    for p in palindromes:
        res.append(print_list(p))    
    return res


# Driver Code
if __name__ == '__main__':
    s = Node(3)
    _list = [7, 6, 8]
    cur = s
    for n in _list:
        new = Node(n)
        cur.next = new
        cur = cur.next

    s2 = Node(3)
    _list = [7, 8, 7, 3]
    cur = s2
    for n in _list:
        new = Node(n)
        cur.next = new
        cur = cur.next
        
    s2_sub = Node(3)
    _list = []
    cur = s2_sub
    for n in _list:
        new = Node(n)
        cur.next = new
        cur = cur.next
        
    test = Node(8)
    _list = [1,2,3,3,2,1,4,9,4,5,6,7,6,5,4,1]
    cur = test
    for n in _list:
        new = Node(n)
        cur.next = new
        cur = cur.next

    print("Q2_a")
    print(print_list(s))
    print(print_list(s2))

    print()

    print("Q2_b")
    print(palindrome(s))
    print(palindrome(s2))
    print(palindrome(s2_sub))

    print()
    
    print("Q2_c")
    print(sub_list(s2, s2_sub))
    
    print()

    print("Q2_d")
    print(max_palindromes(test))
