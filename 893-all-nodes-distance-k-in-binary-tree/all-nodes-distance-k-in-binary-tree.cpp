/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,TreeNode* target){
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* current=queue.front();
            queue.pop();
            if(current->left){
                parent[current->left]=current;
                queue.push(current->left);
            }
            if(current->right){
                parent[current->right]=current;
                queue.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markparent(root,parent,target);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>queue;
        queue.push(target);
        visited[target]=true;
        int curr=0;
        while(!queue.empty()){
            int size=queue.size();
            if(curr++==k)break;
            for(int i=0;i<size;i++){
                TreeNode* current=queue.front();
                queue.pop();
                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right]=true;
                }
                if(parent[current] && !visited[parent[current]]){
                    queue.push(parent[current]);
                    visited[parent[current]]=true;
                }
            }
        }
        vector<int>result;
        while(!queue.empty()){
            TreeNode* current=queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};