class Solution {
public:
    int minInsertions(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        int m=s.length();
        int n=s1.length();
        int a=m-LCS(s,s1,m,n);
        return a;
    }
    int LCS(string &s,string &s1,int m,int n){
        for(int i=0;i<=m;i++){
            t[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            t[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s1[j-1]){
                    t[i][j]=t[i-1][j-1]+1;
                }
                else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[m][n];
            }
    private:
    int t[501][501];
};