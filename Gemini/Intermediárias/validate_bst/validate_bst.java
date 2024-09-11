import java.util.Stack;

class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class BSTValidator {

    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode prev = null;

        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

            root = stack.pop();

            if (prev != null && root.val <= prev.val) {
                return false;
            }

            prev = root;
            root = root.right;
        }

        return true;
    }

    public static void main(String[] args) {
        // Create a sample BST
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(5);
        root.right = new TreeNode(15);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(7);
        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(18);

        // Validate the BST
        BSTValidator validator = new BSTValidator();
        boolean isValid = validator.isValidBST(root);

        if (isValid) {
            System.out.println("The tree is a valid binary search tree.");
        } else {
            System.out.println("The tree is not a valid binary search tree.");
        }
    }
}
