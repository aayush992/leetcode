class Solution {
    private:
    void dfs(int start, vector<vector<int>>& adjLS, vector<int>& vis){
        vis[start]=1;
        for(auto it:adjLS[start]){
            if(!vis[it]){
                dfs(it,adjLS,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int s=isConnected.size();
        vector<vector<int>> adjLS(s);
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }
        vector<int> vis(s, 0);
        int cnt=0;
        for(int i=0;i<s;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLS,vis);
            }
        }
        return cnt;
    }
};