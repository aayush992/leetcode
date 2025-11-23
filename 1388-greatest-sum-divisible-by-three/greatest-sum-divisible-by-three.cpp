class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MIN));

        // base case: at i = n, remainder 0 gives sum 0
        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {

                int include = INT_MIN;
                int nextMod = (j + nums[i] % 3) % 3;

                if (dp[i + 1][nextMod] != INT_MIN)
                    include = nums[i] + dp[i + 1][nextMod];

                int exclude = dp[i + 1][j];

                dp[i][j] = max(include, exclude);
            }
        }

        return dp[0][0] < 0 ? 0 : dp[0][0];
    }
};
