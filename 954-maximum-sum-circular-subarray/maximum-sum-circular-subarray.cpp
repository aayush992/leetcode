class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        long long totalSum = 0;
        long long currMax = 0, maxSum = INT_MIN;
        long long currMin = 0, minSum = INT_MAX;

        for (int num : nums) {
            totalSum += num;

            // Kadane's for max subarray sum
            currMax = max((long long)num, currMax + num);
            maxSum = max(maxSum, currMax);

            // Kadane's for min subarray sum
            currMin = min((long long)num, currMin + num);
            minSum = min(minSum, currMin);
        }

        // If all numbers are negative, maxSum is the answer
        if (maxSum < 0) return maxSum;

        // Max of normal subarray vs circular subarray
        return max(maxSum, totalSum - minSum);
    }
};
