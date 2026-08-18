class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=k-1;
        
        unordered_map<int,int>mp;

        while(j<n){
        int c=0;
        for(c=i;c<=j;c++){
            mp[nums[c]]++;
        }
        i++;
        j++;
        }
        int ans,maxans=-1;

        for(auto it:mp){
            if(it.second==1 || n==k){
                ans=it.first;
                maxans=max(ans,maxans);
            }
        }

        return maxans;

    }
};