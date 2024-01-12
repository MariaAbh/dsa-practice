class Node:
    def __init__(self, val, nexti=None):
        self.val = val
        self.next = nexti

    def __str__(self):
        node = self
        s = ""
        sep = ""
        while node != None:
            s += sep + str(node.val)
            node = node.next
            sep = " "
        return s

def swap_pairs(n):
    node = n
    while node != None and node.next != None and node.next.next != None:
        if node == n:
            temp = node.next
            node.next = node.next.next
            temp.next = node
            n = temp
        else:
            temp = node.next.next
            node.next.next = node.next.next.next
            temp.next = node.next
            node.next = temp
            node = node.next.next
    return n

def main():
    node = Node(6)
    node.next = Node(5)
    node.next.next = Node(4)
    node.next.next.next = Node(3)

    node = None
    for v in 6,5,4,3:
        node = Node(v,node)
    
    print('Before:',node)
    print('After :',swap_pairs(node))

    node = Node(6)
    node.next = Node(5)
    node.next.next = Node(4)

    print('Before:',node)
    print('After :',swap_pairs(node))

main()
