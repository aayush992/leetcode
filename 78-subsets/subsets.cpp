class Solution {
public:
    void print(int index,vector<int>nums,vector<vector<int>>& ans,vector<int>& ds,int n){
        if(index==n){
            ans.push_back(ds);
            return ;
        }
   
        print(index+1,nums,ans,ds,n);
        ds.push_back(nums[index]);
        print(index+1,nums,ans,ds,n);
        ds.pop_back();


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        print(0,nums,ans,ds,n);
        return ans;
    }
};