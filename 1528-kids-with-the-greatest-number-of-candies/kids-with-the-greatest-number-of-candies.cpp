class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool>ab(n,false);
        int max=candies[0];
        for(int i=1;i<n;i++){
            if(candies[i]>max)
            max=candies[i];
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=max){
                ab[i]='true';
            }
        }
        return ab;
    }
};