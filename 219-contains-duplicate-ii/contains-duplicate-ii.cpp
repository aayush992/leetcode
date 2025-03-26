class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen; // Stores element and its index
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i]) && i - seen[nums[i]] <= k) {
                return true; // Duplicate found within range
            }
            seen[nums[i]] = i; // Update index of current element
        }
        return false; // No such duplicates found
    }
};