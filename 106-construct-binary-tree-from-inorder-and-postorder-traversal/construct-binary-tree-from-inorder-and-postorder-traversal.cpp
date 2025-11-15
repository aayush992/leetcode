class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return NULL;

        map<int,int> mpp;
        for (int i = 0; i < inorder.size(); i++)
            mpp[inorder[i]] = i;

        return buildTreePostIn(inorder, 0, inorder.size()-1,
                               postorder, 0, postorder.size()-1,
                               mpp);
    }

    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie,
                              vector<int>& postorder, int ps, int pe,
                              map<int,int>& mpp) 
    {
        if (ps > pe || is > ie) 
            return NULL;

        // Root is the last element of postorder
        TreeNode* root = new TreeNode(postorder[pe]);

        int inRoot = mpp[root->val];    // index in inorder
        int numsLeft = inRoot - is;     // # of nodes in left subtree

        // Build Left Subtree
        root->left = buildTreePostIn(
            inorder, is, inRoot - 1,
            postorder, ps, ps + numsLeft - 1,
            mpp
        );

        // Build Right Subtree
        root->right = buildTreePostIn(
            inorder, inRoot + 1, ie,
            postorder, ps + numsLeft, pe - 1,
            mpp
        );

        return root;
    }
};
