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
      /* void solve(TreeNode* root,vector<int>&result)
     {
         if(root==NULL)
             return;result.push_back(root->val);
         solve(root->left,result);
            solve(root->right,result);
         
      
        
      }*/
      vector<int> solve(TreeNode* root, vector<int>&result){
        stack<TreeNode*>st;
        if(root==NULL){
            return result;
        }
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            result.push_back(root->val);
            if(root->right!=NULL){
                st.push(root->right);
            }
            if(root->left!=NULL){
                st.push(root->left);
            }
        }
        return result;
      }
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>result;
        solve(root,result);
        return result;
    }
};