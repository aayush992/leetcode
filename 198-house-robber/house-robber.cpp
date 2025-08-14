class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==0)return 0;
       if(n==1)return nums[0];
       int prev1=nums[0];
       int prev2=max(nums[0],nums[1]);
            for (int i = 2; i < n; i++) {
            int curr = max(prev2, prev1 + nums[i]); // rob this or skip
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
       
    }
};


/*
 int c=0;
        int even=0,odd=0;
        for(int i=0;i<nums.size();i++){
                if(i%2==0){
                    even =even+nums[i];
                }
                else odd=odd+nums[i];
                c=max(even,odd);
        }
        return c;
        */
        