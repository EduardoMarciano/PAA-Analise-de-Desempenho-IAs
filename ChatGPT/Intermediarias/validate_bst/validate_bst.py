class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        inorder = []

        def traverse(node):
            if not node:
                return True
            if not traverse(node.left):
                return False
            if inorder and node.val <= inorder[-1]:
                return False
            inorder.append(node.val)
            return traverse(node.right)

        return traverse(root)

# Exemplo de execução
if __name__ == "__main__":
    # Criação de uma árvore binária
    #       2
    #      / \
    #     1   3
    node1 = TreeNode(1)
    node3 = TreeNode(3)
    root = TreeNode(2, node1, node3)

    # Cria uma instância da solução e verifica se a árvore é uma BST
    sol = Solution()
    result = sol.isValidBST(root)
    print("A árvore é uma BST válida:", result)

    # Criação de uma árvore binária que não é uma BST
    #       5
    #      / \
    #     1   4
    #        / \
    #       3   6
    node1 = TreeNode(1)
    node3 = TreeNode(3)
    node6 = TreeNode(6)
    node4 = TreeNode(4, node3, node6)
    root = TreeNode(5, node1, node4)

    # Verifica se a segunda árvore é uma BST
    result = sol.isValidBST(root)
    print("A segunda árvore é uma BST válida:", result)
