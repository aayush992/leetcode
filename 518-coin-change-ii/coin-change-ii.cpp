class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // use unsigned long long to avoid overflow
        vector<vector<unsigned long long>> t(n + 1, vector<unsigned long long>(amount + 1, 0));

        // Base case: making amount = 0 → 1 way (by choosing nothing)
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        // DP filling
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    // Include coin[i-1] + Exclude coin[i-1]
                    t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
                } else {
                    // Exclude coin[i-1]
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return (int)t[n][amount]; // safe cast, final result fits in int
    }
};
