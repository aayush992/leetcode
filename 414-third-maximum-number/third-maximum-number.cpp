class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int distinctCount = 1; 

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                distinctCount++;
                if (distinctCount == 3) {
                    return nums[i]; 
                }
            }
        }

        return nums[0];
    }
};