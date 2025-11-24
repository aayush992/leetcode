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
class BSTIterator {
private:
    stack<TreeNode*> mystack;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* tempnode = mystack.top();
        mystack.pop();
        pushAll(tempnode->right);
        return tempnode->val;
    }

    bool hasNext() {
        return !mystack.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            mystack.push(node);
            node = node->left;
        }
    }
};
