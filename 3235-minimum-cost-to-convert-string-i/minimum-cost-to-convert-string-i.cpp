class Solution {
public:
    /*
        Using Floyd–Warshall algorithm (multi-source shortest path)

        Idea:
        - Each character (a–z) is treated as a node (26 nodes total)
        - original[i] -> changed[i] with cost[i] represents a directed edge
        - We compute the minimum cost to convert any character to any other
    */
    void flyod_warshall(
        vector<vector<long long>>& adjmatrix,
        vector<char>& original,
        vector<char>& changed,
        vector<int>& cost
    ) {
        // Step 1: Initialize direct transformation costs
        // O(N) where N = number of transformations
        for (int i = 0; i < original.size(); i++) {
            int s = original[i] - 'a';   // source character index
            int t = changed[i] - 'a';    // target character index

            // Store minimum direct cost for s -> t
            adjmatrix[s][t] = min(adjmatrix[s][t], (long long)cost[i]);
        }

        // Step 2: Floyd–Warshall Algorithm
        // Computes shortest paths between all pairs of characters
        // Time Complexity: 26 * 26 * 26 ≈ constant
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    // Avoid overflow when adding large values
                    if (adjmatrix[i][k] != INT_MAX && adjmatrix[k][j] != INT_MAX) {
                        adjmatrix[i][j] = min(
                            adjmatrix[i][j],
                            adjmatrix[i][k] + adjmatrix[k][j]
                        );
                    }
                }
            }
        }
    }

    long long minimumCost(
        string source,
        string target,
        vector<char>& original,
        vector<char>& changed,
        vector<int>& cost
    ) {
        // Adjacency matrix for 26 lowercase letters
        // adjmatrix[i][j] = minimum cost to convert (char)(i+'a') -> (char)(j+'a')
        vector<vector<long long>> adjmatrix(26, vector<long long>(26, INT_MAX));

        // Run Floyd–Warshall to compute all-pairs minimum conversion cost
        flyod_warshall(adjmatrix, original, changed, cost);

        long long ans = 0;

        // Calculate total cost to convert source → target
        for (int i = 0; i < source.size(); i++) {

            // No cost if characters are already same
            if (source[i] == target[i]) {
                continue;
            }

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            // If conversion is not possible
            if (adjmatrix[u][v] == INT_MAX) {
                return -1;
            }

            ans += adjmatrix[u][v];
        }

        return ans;
    }
};
