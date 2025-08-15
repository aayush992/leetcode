class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        if(n==0)return 0;
        vector<int>dp(n);
        dp[0]=nums[0];
        int maxi=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
            maxi=max(maxi,dp[i]);
        }
        return maxi;
     /* int sum=0,maxi=INT_MIN;
      int n=nums.size();
      for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
      }
      return maxi;*/
      
      
      /* int n=nums.size();
       int maxi=INT_MIN;
       for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            maxi=max(maxi,sum);
        }
       }
       return maxi;*/
       
       /* int n=nums.size();
         int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                    int sum=0;
                    for(int k=i;k<=j;k++){
                        sum+=nums[k];
                    }
                    maxi=max(sum,maxi);
            }
        }
         return maxi;*/
    }
};

