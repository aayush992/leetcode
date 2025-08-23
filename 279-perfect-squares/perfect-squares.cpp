class Solution {
public:
    int numSquares(int n) {
         if(n<=0){
            return 0;
         }
         vector<int>cnt({0});
         while(cnt.size()<=n){
            int m=cnt.size();
            int cnt1=INT_MAX;
            for(int i=1;i*i<=m;i++){
                cnt1=min(cnt1,cnt[m-i*i]+1);
            }
            cnt.push_back(cnt1);
         }
         return cnt[n];
     
     
     
     
      /*  if(n<=0){
            return 0;
        }
        vector<int>cnt(n+1,INT_MAX);
        cnt[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                cnt[i]=min(cnt[i],cnt[i-j*j]+1);
            }
        }
        return cnt[n];
        */
    }
};