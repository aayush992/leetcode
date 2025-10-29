class Solution {
public:
    // Helper function that returns height or -1 if unbalanced
    int checkHeight(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1; // left subtree unbalanced

        int right = checkHeight(root->right);
        if (right == -1) return -1; // right subtree unbalanced

        if (abs(left - right) > 1)
            return -1; // current node unbalanced

        return max(left, right) + 1; // return height if balanced
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
