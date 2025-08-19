class Solution {
public:
    int count(const vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));
        t[0][0] = 1; // 1 way to make sum 0 with 0 items

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) { // NOTE: start at 0
                t[i][j] = t[i - 1][j];          // exclude nums[i-1]
                if (nums[i - 1] <= j) {
                    t[i][j] += t[i - 1][j - nums[i - 1]]; // include it
                }
            }
        }
        return t[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (llabs(target) > total) return 0;
        if ((total + target) % 2 != 0) return 0;       // impossible
        int need = int((total + target) / 2);
        return count(nums, need);
    }
};
