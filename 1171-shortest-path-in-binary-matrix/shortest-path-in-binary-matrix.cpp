class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // Distance matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;

        // Start from (0,0)
        q.push({0, 0});
        dist[0][0] = 1;

        // 8 directions
        int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Reached destination
            if (x == n-1 && y == n-1)
                return dist[x][y];

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 &&
                    dist[nx][ny] > dist[x][y] + 1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};
