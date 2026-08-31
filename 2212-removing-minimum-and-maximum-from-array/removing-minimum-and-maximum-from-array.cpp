class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2){
            return n;
        }
        int i=0,j=n-1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int min_idx=0,max_idx=0;

        while(i<=j){
            if(nums[i]>maxi){
                maxi=nums[i];
                max_idx=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                min_idx=i;
            }
            if(nums[j]>maxi){
                maxi=nums[j];
                max_idx=j;
            }
            if(nums[j]<mini){
                mini=nums[j];
                min_idx=j;
            }
            i++;
            j--;
        }
        
        int left = max(min_idx, max_idx) + 1;
        int right = n - min(min_idx, max_idx);
        int both = min(min_idx, max_idx) + 1 + n - max(min_idx, max_idx);

        return min({left, right, both});
        
    }
};