class Solution {
public:
        int t[501][501];
    int solve(int i, int j,vector<int>& piles){

        if (i > j)
    return 0;

       

    if(t[i][j]!=-1)return t[i][j];

        int one=piles[i]+min(solve(i+2,j,piles),solve(i+1,j-1,piles));

        int two=piles[j]+min(solve(i+1,j-1,piles),solve(i,j-2,piles));

        return t[i][j]= max(one,two);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();

        memset(t,-1,sizeof(t));
        
        int sum =accumulate(begin(piles),end(piles),0);
        int a= solve(0,n-1,piles);

        int b=sum-a;
        if(a>b)return true;
        else return false;
    }
};