class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 1, n = nums.size();
        int l = 0, r = 0, bits = 0;

        while (r < n) {
            while ((bits & nums[r]) != 0) {  // Condition fails, remove nums[l]
                bits ^= nums[l];
                l++;
            }
            bits |= nums[r];  // Add nums[r] to the window
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};