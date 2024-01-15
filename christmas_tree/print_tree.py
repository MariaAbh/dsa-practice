def print_tree(n):
    max_nodes = (n*2)-1
    mid = max_nodes//2
    nodes = [' ']*max_nodes
    start = mid
    end = mid
    for i in range(n):
        nodes[start] = "*"
        nodes[end] = "*"
        print(*nodes, sep='')
        start -= 1
        end += 1
    for i in range(2):
        print(' '*(mid) +'*'+' '*(mid)) 

n = 5
print_tree(n)
