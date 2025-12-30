class Solution {
private:
  /*  bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& pathVis,
             vector<int>& topo) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis, topo))
                    return true;
            }
            else if(pathVis[it]) {
                return true; // cycle detected
            }
        }

        pathVis[node] = 0;
        topo.push_back(node); // store order
        return false;
    }
*/
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         // adjacency list
        vector<vector<int>> adj(numCourses);

        // build graph
        // v -> u  (to take u, first complete v)
        for(auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        // indegree array
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // queue for courses with indegree 0
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo; // stores course order

        // Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            // reduce indegree of neighbours
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        // if cycle exists, topo size will be less
        if(topo.size() != numCourses)
            return {};

        return topo;
/*
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);  // v -> u
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int> topo;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis, topo))
                    return {}; // cycle found
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
        */
    }
};
