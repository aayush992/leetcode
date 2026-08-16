class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
         int n=nums.size();
        int resultXOR=0;

        bool allzero=true;
        for(int &x: nums){
            resultXOR =(resultXOR ^ x);
                if(x!=0){
                    allzero=false;
                }
            }

            if(allzero){
                return 0;
            }

            return(resultXOR==0)?n-1:n;   
    }
};