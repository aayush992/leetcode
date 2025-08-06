class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
       lcs(text1,text2,m,n);
      return t[m][n];
    }
    private:
    int t[1000+1][1000+1];

    int lcs(string &text1, string &text2,int m,int n){
          for(int i=0;i<m;i++){
            t[i][0]=0;
          }
          for(int j=0;j<n;j++){
            t[0][j]=0;
          }
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
        if(text1[i-1]==text2[j-1]){
         t[i][j]= 1+ t[i-1][j-1];
        }
        else  t[i][j] =max(t[i-1][j],t[i][j-1]); 
    }
            }
            return t[m][n];
    }
};





/*          Recursive approach- TLE 

int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
       lcs(text1,text2,m,n);
       return lcs(text1, text2, m, n);
    }
    private:
    int lcs(string &text1, string &text2,int m,int n){
             if(m==0||n==0){
            return 0;
        }
        if(text1[m-1]==text2[n-1]){
          return  1+lcs(text1,text2,m-1,n-1);
        }
        else return max(lcs(text1,text2,m-1,n),lcs(text1,text2,m,n-1)); 
    }

            memoization approach-tle

    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        memset(t,-1,sizeof(t));
       lcs(text1,text2,m,n);
       return lcs(text1, text2, m, n);
    }
    private:
    int t[1000+1][1000+1];

    int lcs(string &text1, string &text2,int m,int n){
             if(m==0||n==0){
            return 0;
        }
        if(text1[m-1]==text2[n-1]){
          return t[m][n]= 1+lcs(text1,text2,m-1,n-1);
        }
        else return t[m][n] =max(lcs(text1,text2,m-1,n),lcs(text1,text2,m,n-1)); 
    }
    
    
    */
