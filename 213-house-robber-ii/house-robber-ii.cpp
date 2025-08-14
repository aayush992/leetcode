class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return nums[1]; // rob from index 1 only

        int prev1 = nums[1];
        int prev2 = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++) {
            int curr = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int rob2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]); // rob from index 0 or 1

        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            int curr = max(prev2, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        return max(rob1(nums), rob2(nums));
    }
};
