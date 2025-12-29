class Solution {
private:
    // DFS function to detect cycle
    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& vis,
             vector<int>& pathVis,
             vector<int>& safe) {

        // mark current node visited
        vis[node] = 1;
        pathVis[node] = 1;

        // initially assume node is unsafe
        safe[node] = 0;

        // traverse all adjacent nodes
        for(auto it : graph[node]) {

            // if adjacent node not visited
            if(!vis[it]) {
                if(dfs(it, graph, vis, pathVis, safe))
                    return true;   // cycle found
            }
            // if node already in current path → cycle
            else if(pathVis[it]) {
                return true;
            }
        }

        // backtrack from current path
        pathVis[node] = 0;

        // no cycle found from this node → safe
        safe[node] = 1;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        // vis → visited
        // pathVis → current DFS path
        // safe → eventual safe nodes
        vector<int> vis(n, 0), pathVis(n, 0), safe(n, 0);

        // run DFS for all nodes
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, graph, vis, pathVis, safe);
            }
        }

        // collect all safe nodes
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(safe[i] == 1)
                ans.push_back(i);
        }

        return ans;
    }
};
