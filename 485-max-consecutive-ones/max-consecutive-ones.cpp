class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       /* int c=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                c++;}
            else c=0;
                maxi=max(maxi,c);
        }
        return maxi; */
        int l=0,r=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                r++;
            }
            else if(nums[i]==0){
                l=r+1;
                r++;
            }
            c=max(r-l,c);
        }
        return c;
    }
};