class TreeNode:
    def __init__(self, value=0, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def serialize(node):
    arr = []

    def traverse(curr):
        if curr is None:
            arr.append(None)
            return
        
        arr.append(curr.value) 
        traverse(curr.left)
        traverse(curr.right)
        
    traverse(node) 
    return arr

def deserialize(arr):
    ind = 0

    def built():
        nonlocal ind

        if arr[ind] is None:
            ind = ind + 1
            return None
        
        node = TreeNode(arr[ind])

        ind = ind + 1
        node.left = built() 
        node.right = built()
    
        return node
    
    return built()
        
if __name__ == "__main__":
    root = TreeNode(0)
    arr = serialize(root)
    node = deserialize(arr)