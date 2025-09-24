class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = length of the LIS ending at index i
        // cnt[i] = number of LIS ending at index i
        vector<int> dp(n, 1), cnt(n, 1);

        int maxi = 1; // keeps track of the maximum LIS length so far

        // Step 1: Compute LIS length and counts
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                // Case 1: We found a longer LIS ending at i via prev
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];   // update LIS length
                    cnt[i] = cnt[prev];     // reset count = count of prev
                }
                // Case 2: We found another LIS of the same length ending at i
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) {
                    cnt[i] += cnt[prev];    // add more ways
                }
            }
            // update the global maximum LIS length
            maxi = max(maxi, dp[i]);
        }

        // Step 2: Count how many subsequences have the maximum length
        int nos = 0; // number of LIS
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) nos += cnt[i];
        }

        return nos;
    }
};
