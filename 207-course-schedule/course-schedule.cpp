class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // adjacency list
        vector<vector<int>> adj(numCourses);

        // build directed graph
        // v -> u (to take u, first complete v)
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

        // queue for nodes with indegree 0
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;  // count of processed nodes

        // Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        // if all courses processed → possible
        return cnt == numCourses;
    }
};
