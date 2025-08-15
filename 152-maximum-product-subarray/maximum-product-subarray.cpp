class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n= nums.size();
        if(n==0)return 0;
        long long minprod=nums[0];
        long long maxprod=nums[0];
        long long ans =nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                swap(maxprod,minprod);
            }
            maxprod=max((long long)nums[i],maxprod*nums[i]);
            minprod=min((long long)nums[i],minprod*nums[i]);
            ans=max(ans,maxprod);
        }
        return max(ans,minprod);
     /* long sum=0,maxi=INT_MIN;
      int n=nums.size();
      for(int i=0;i<n;i++){
            sum=sum*nums[i];
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
      }
      return maxi;*/
    }
};