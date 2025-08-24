class Solution {
public:
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        int m=word1.length();
        int n=word2.length();
        for(int i=0;i<=m;i++){
            t[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            t[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    t[i][j]=t[i-1][j-1]+1;
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        int a=t[m][n];
        return (m-a)+(n-a);

    }
    private:
    int t[501][501];
};