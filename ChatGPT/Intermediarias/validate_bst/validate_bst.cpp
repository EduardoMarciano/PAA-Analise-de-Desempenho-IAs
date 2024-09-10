#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Função para verificar se uma árvore binária é uma BST
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return inorder(root, prev);
    }

private:
    // Função auxiliar para fazer a travessia em ordem
    bool inorder(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr) {
            return true;
        }

        // Visite a subárvore esquerda
        if (!inorder(node->left, prev)) {
            return false;
        }

        // Verifique se o nó atual é maior que o nó anterior na travessia em ordem
        if (prev != nullptr && node->val <= prev->val) {
            return false;
        }

        // Atualiza o nó anterior para o atual antes de visitar a subárvore direita
        prev = node;

        // Visite a subárvore direita
        return inorder(node->right, prev);
    }
};

int main() {
    // Criação de uma árvore binária que é uma BST
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    std::cout << "A árvore é uma BST válida: " << (sol.isValidBST(root) ? "Sim" : "Não") << std::endl;

    // Criação de uma árvore binária que não é uma BST
    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    std::cout << "A segunda árvore é uma BST válida: " << (sol.isValidBST(root2) ? "Sim" : "Não") << std::endl;

    return 0;
}
