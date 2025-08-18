class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        // If sum is odd, cannot partition
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        
        // DP table
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));
        
        // Base cases
        for (int i = 0; i <= n; i++) {
            t[i][0] = true;  // sum 0 possible with any i
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        
        return t[n][target];
    }
};
