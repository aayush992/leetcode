class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, zeros = 0, maxlen = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) zeros++;
            
            while (zeros > k) {  // shrink until valid
                if (nums[l] == 0) zeros--;
                l++;
            }
            
            // here zeros <= k, so window [l..r] is valid
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
