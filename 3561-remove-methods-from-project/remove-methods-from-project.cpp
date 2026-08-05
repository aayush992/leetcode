class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& seen) {
        if (seen.count(node))
            return;

        seen.insert(node);

        for (int nei : adj[node]) {
            dfs(nei, adj, seen);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto& invocation : invocations) {
            int u = invocation[0];
            int v = invocation[1];
            adj[u].push_back(v);
        }

        unordered_set<int> seen;

        dfs(k, adj, seen);

        for (auto &invocation : invocations) {
            int u = invocation[0];
            int v = invocation[1];

            if (!seen.count(u) && seen.count(v)) {
                vector<int> result;
                // we cannot remove anything
                for (int i = 0; i < n; i++)
                    result.push_back(i);

                return result;
            }
        }

        vector<int> result;
        // remove the sus node
        for (int i = 0; i < n; i++) {
            if (!seen.count(i))
                result.push_back(i);
        }

        return result;
    }
};