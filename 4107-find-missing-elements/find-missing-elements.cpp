class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty())return{};
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        int a=nums.front();
        int c=nums.back();
        for(int i=a+1;i<c;i++){
               if (!binary_search(nums.begin(), nums.end(), i))

                ans.push_back(i);
       }
       return ans;
    }
};