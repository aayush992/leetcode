class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;

        // store index of inorder elements
        for(int i=0; i<inorder.size(); i++)
            mpp[inorder[i]] = i;

        return BuildTree(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1,
                         mpp);
    }

    TreeNode* BuildTree(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> &inorder, int inStart, int inEnd,
                        map<int,int> &mpp) {

        if(preStart > preEnd || inStart > inEnd)
            return nullptr;  // ✅ FIXED

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[root->val];       // index of root in inorder
        int numLeft = inRoot - inStart;    // number of nodes in left subtree

        root->left = BuildTree(preorder,
                               preStart + 1,
                               preStart + numLeft,
                               inorder,
                               inStart,
                               inRoot - 1,
                               mpp);

        root->right = BuildTree(preorder,
                                preStart + numLeft + 1,   // ✅ FIXED
                                preEnd,
                                inorder,
                                inRoot + 1,
                                inEnd,
                                mpp);

        return root;
    }
};
