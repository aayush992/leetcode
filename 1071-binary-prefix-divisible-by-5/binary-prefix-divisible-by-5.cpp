class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>result(n);
        int rem=0;
        for(int i=0;i<n;i++){
            rem=(rem*2+nums[i])%5;
            result[i]=(rem==0);
        }
        return result;
    }
};