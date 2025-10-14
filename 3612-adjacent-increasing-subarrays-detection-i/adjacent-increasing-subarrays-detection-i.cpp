class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> isInc(n, false);

        // Mark increasing subarrays of length k
        for (int i = 0; i + k <= n; i++) {
            bool inc = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    inc = false;
                    break;
                }
            }
            isInc[i] = inc;
        }

        // Check for adjacent increasing subarrays
        for (int i = 0; i + 2 * k <= n; i++) {
            if (isInc[i] && isInc[i + k]) {
                return true;
            }
        }

        return false;
    }
};
