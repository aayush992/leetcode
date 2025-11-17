class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1;   // index of previous 1

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (prev != -1 && (i - prev - 1) < k)
                    return false;   // too close
                
                prev = i; // update previous 1 index
            }
        }
        return true;
    }
};
