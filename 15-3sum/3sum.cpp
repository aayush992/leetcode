
class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
       sort(nums.begin(), nums.end());
        //using two pointer
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {// i will start from zero left from 1st index and right from last index
                continue; // Skip duplicate elements
            }
            // start from i+1 index 
            int left = i + 1;
            int right = nums.size() - 1;// start from last index

            while (left < right) {// 
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {// if sum is zero store the elements in the answer vector
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicate elements
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    ++left;//if no duplicate elements found increment left
                    --right;//if  no duplicate elements  found decrement right
                } else if (sum < 0) {
                    ++left;//if our sum is less than 0 then increment left since our vector was sorted
                } else {
                    --right;//else decrement right as we have a large sum than 0 
                }
            }
        }

        return ans;
    }
};