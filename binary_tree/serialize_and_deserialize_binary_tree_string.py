class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
def serialize(node):
    arr = []

    def traverse(curr): 
        if curr is None:
            arr.append("#")
            return

        arr.append(str(curr.val))
        traverse(curr.left)
        traverse(curr.right)
    
    traverse(node)

    return ",".join(arr)


def deserialize(s):
    if not s: 
        return None

    values = s.split(",")
    itr = iter(values)

    def build():
        curr = next(itr, None)

        if curr is None or curr == "#":
            return None
        
        node = TreeNode(int(curr))
        node.left = build()
        node.right = build()
        
        return node
    
    return build()