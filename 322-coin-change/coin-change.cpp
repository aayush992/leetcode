class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        const int INF = 1e9; // large number (simulate infinity)
        vector<vector<int>> t(n + 1, vector<int>(amount + 1, INF));

        // Base case: 0 amount = 0 coins
        for (int i = 0; i <= n; i++) {
            t[i][0] = 0;
        }

        // Base case: 0 coins can't make any positive amount
        for (int j = 1; j <= amount; j++) {
            t[0][j] = INF;
        }

        // DP filling
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    if (t[i][j - coins[i - 1]] != INF)
                        t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
                    else
                        t[i][j] = t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        if (t[n][amount] == INF) {
    return -1;   // means impossible to form the amount
} else {
    return t[n][amount];  // return the minimum number of coins
}

    }
};
