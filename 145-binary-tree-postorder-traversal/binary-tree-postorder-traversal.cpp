/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<int>& result) {
        if (!root) return;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr; // previously processed node

        while (!st.empty() || curr != nullptr) {
            // reach the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* top = st.top();

            // if right child is null or already processed, process current node
            if (top->right == nullptr || top->right == prev) {
                result.push_back(top->val);
                st.pop();
                prev = top;
            } 
            else {
                // otherwise, move to right subtree
                curr = top->right;
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
};
