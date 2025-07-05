class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0,r=0;
        int m=g.size();
        int n=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<n && r<m){
            if(g[r]<=s[l]){
                r=r+1;
            }
            l=l+1;
        }
        return r;
    }
};