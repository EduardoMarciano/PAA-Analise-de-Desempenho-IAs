#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root) {
    if (!root) {
        return true;
    }

    if (root->left && root->left->val >= root->val) {
        return false;
    }

    if (root->right && root->right->val <= root->val) {
        return false;
    }

    return isValidBST(root->left) && isValidBST(root->right);
}

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);

    // Validate the BST
    bool isValid = isValidBST(root);

    if (isValid) {
        cout << "The tree is a valid binary search tree." << endl;
    } else {
        cout << "The tree is not a valid binary search tree." << endl;
    }

    return 0;
}
