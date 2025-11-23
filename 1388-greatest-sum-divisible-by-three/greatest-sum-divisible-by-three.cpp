class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));

        // base condition: at idx = n, mod = 0 → sum = 0
        dp[n][0] = 0;

        // build from bottom to top
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int mod = 0; mod < 3; mod++) {

                int include = INT_MIN;
                int nextMod = (mod + nums[idx] % 3) % 3;

                if (dp[idx + 1][nextMod] != INT_MIN)
                    include = nums[idx] + dp[idx + 1][nextMod];

                int exclude = dp[idx + 1][mod];

                dp[idx][mod] = max(include, exclude);
            }
        }

        return dp[0][0] < 0 ? 0 : dp[0][0];
    }
};
