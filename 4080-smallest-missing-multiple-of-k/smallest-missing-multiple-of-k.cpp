class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(auto it:nums){
            if(it%k==0){
                st.insert(it);
            }
        }
        int ans=k;
        while(st.contains(ans)){
            ans+=k;

        }
        return ans;
        
    }
};