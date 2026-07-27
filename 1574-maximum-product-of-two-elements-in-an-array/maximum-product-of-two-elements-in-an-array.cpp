class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            if((nums[i-1]-1)*(nums[j]-1)>ans){
                ans=(nums[i-1]-1)*(nums[j]-1);
            }
        }
        }
        return ans;
    }
};