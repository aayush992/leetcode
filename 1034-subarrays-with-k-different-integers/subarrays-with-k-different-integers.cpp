class Solution {
public:
    // Helper function: count subarrays with at most k distinct
    int func(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0;
        map<int, int> mpp;

        while (r < nums.size()) {
            mpp[nums[r]]++;

            // Shrink window if more than k distinct
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;
            }

            // Add count of valid subarrays ending at r
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

    // Main function: exactly k distinct
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k - 1);       
       
       
       /* int cnt=0;
        for(int i=0;i<nums.size();i++){
            map<int,int>mpp;
            for(int j=i;j<nums.size();j++){
                mpp[nums[j]]++;
                if(mpp.size()==k)
                cnt=cnt+1;
                else if(mpp.size()>k)break;
            }
    }
    return cnt; */
    }
};