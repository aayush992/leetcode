class Solution {
public:
    int ans = 0;
    unordered_map<int, vector<int>> company;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; i++) {
            int t = manager[i];
            if (t != -1) {
                company[t].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }

    int dfs(int head, vector<int>& informTime) {
        int m = ans;  // Initialize m properly
        for (auto it : company[head]) {
            ans += informTime[head];
            m = max(m, dfs(it, informTime));  // Update m correctly
            ans -= informTime[head];
        }
        return m;
    }
};