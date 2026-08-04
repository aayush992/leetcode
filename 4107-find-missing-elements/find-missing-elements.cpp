class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       
       int n=nums.size();
       sort(nums.begin(),nums.end());
        vector<int>ans;
       for(int i=0;i<n-1;i++){
        int curr=nums[i];
        int next=nums[i+1];

        if(next>curr+1){
            for(int missing=curr+1; missing<next; missing++){
                ans.push_back(missing);
            }
        }
       }
       return ans;
       
       
       
       
       
       
       
       
       
       
       
       
       
       /* if(nums.empty())return{};
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        int a=nums.front();
        int c=nums.back();
        for(int i=a+1;i<c;i++){
               if (!binary_search(nums.begin(), nums.end(), i))

                ans.push_back(i);
       }
       return ans;*/
    }
};