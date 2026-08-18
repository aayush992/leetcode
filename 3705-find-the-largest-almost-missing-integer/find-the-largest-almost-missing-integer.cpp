class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = k - 1;

        unordered_map<int, int> mp;

        while(j < n) {

            unordered_set<int> seen;

            for(int c = i; c <= j; c++) {
                if(seen.find(nums[c]) == seen.end()) {
                    mp[nums[c]]++;
                    seen.insert(nums[c]);
                }
            }

            i++;
            j++;
        }

        int maxans = -1;

        for(auto it : mp) {
            if(it.second == 1) {
                maxans = max(maxans, it.first);
            }
        }

        return maxans;
    }
};