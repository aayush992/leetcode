class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1; // sum 0 seen once
        int sum = 0, count = 0;

        for(int num : nums) {
            sum += num;

            // if (sum - k) was seen before, that means
            // there exists a subarray ending here with sum=k
            if(prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }

            prefixCount[sum]++;
        }

        return count;


          /*  int count=0;
            for(int i=0;i<nums.size();i++){
                int sum=nums[i];
                if(sum==k)
                count++;
                for(int j=i+1;j<nums.size();j++){
                        sum+=nums[j];
                        if(sum==k)
                        count++;
                }
                
            }
            return count; */
    }
};