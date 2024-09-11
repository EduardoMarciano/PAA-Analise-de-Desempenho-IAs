#include <iostream>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool isValidBSTHelper(TreeNode* node, long long min, long long max) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= min || node->val >= max) {
            return false;
        }

        return isValidBSTHelper(node->left, min, node->val) &&
               isValidBSTHelper(node->right, node->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
};

// Test function
void test() {
    // Create a valid BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution solution;
    bool isValid = solution.isValidBST(root);

    std::cout << "Is the tree a valid BST? " << (isValid ? "Yes" : "No") << std::endl;
}

int main() {
    test();
    return 0;
}
