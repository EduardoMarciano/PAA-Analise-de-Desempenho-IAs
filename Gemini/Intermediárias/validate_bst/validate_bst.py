class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isValidBST(root):
    def helper(node, lower=float('-inf'), upper=float('inf')):
        if not node:
            return True
        val = node.val
        if val <= lower or val >= upper:
            return False
        if not helper(node.left, lower, val):
            return False
        return helper(node.right, val, upper)

    return helper(root)

def test_isValidBST():
    # Caso 1: Árvore válida
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(15)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(7)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(18)
    assert isValidBST(root) == True

    # Caso 2: Árvore inválida (valor duplicado)
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(15)
    root.left.left = TreeNode(5)
    assert isValidBST(root) == False


if __name__ == "__main__":
    test_isValidBST()
