class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Solution {

    private TreeNode prev = null;

    public boolean isValidBST(TreeNode root) {
        return inorder(root);
    }

    private boolean inorder(TreeNode node) {
        if (node == null) {
            return true;
        }

        // Visita a subárvore esquerda
        if (!inorder(node.left)) {
            return false;
        }

        // Verifica se o nó atual é maior que o anterior visitado
        if (prev != null && node.val <= prev.val) {
            return false;
        }

        // Atualiza o nó anterior para o atual
        prev = node;

        // Visita a subárvore direita
        return inorder(node.right);
    }

    public static void main(String[] args) {
        // Exemplo de árvore que é uma BST
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);

        Solution sol = new Solution();
        System.out.println(
            "A árvore é uma BST válida: " + sol.isValidBST(root)
        );

        // Exemplo de árvore que não é uma BST
        TreeNode root2 = new TreeNode(5);
        root2.left = new TreeNode(1);
        root2.right = new TreeNode(4);
        root2.right.left = new TreeNode(3);
        root2.right.right = new TreeNode(6);

        System.out.println(
            "A segunda árvore é uma BST válida: " + sol.isValidBST(root2)
        );
    }
}
