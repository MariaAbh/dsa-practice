class TreeNode:
    def __init__(self, x, left=None, right=None):
        self.val = x
        self.left = left
        self.right = right
    
    def bfs(self):
        root = self
        current_nodes = [root]
        result = []
        while len(current_nodes) != 0:

            temp = []
            node_values = []
            for r in current_nodes:
                node_values.append(r.val)
                if r.left != None:
                    temp.append(r.left)
                if r.right != None:
                    temp.append(r.right)
            result.append(node_values)
            current_nodes = [i for i in temp]

        return result
            

def main():
    root = TreeNode(10,TreeNode(23,TreeNode(4),TreeNode(2023)),TreeNode(31,TreeNode(72,TreeNode(27),TreeNode(12)),TreeNode(42)))
    print(root.bfs())
main()
