class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Step 1: Fill LCS table
        for (int i = 0; i <= m; i++) {
            t[i][0] = 0;
        }
        for (int j = 0; j <= n; j++) {
            t[0][j] = 0;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        // Step 2: Build the SCS string using the DP table
        int i = m, j = n;
        string result = "";

        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                result += text1[i - 1];
                i--;
                j--;
            } else if (t[i - 1][j] > t[i][j - 1]) {
                result += text1[i - 1];
                i--;
            } else {
                result += text2[j - 1];
                j--;
            }
        }

        // If any characters are left in text1 or text2
        while (i > 0) {
            result += text1[i - 1];
            i--;
        }
        while (j > 0) {
            result += text2[j - 1];
            j--;
        }

        // The result is built in reverse
        reverse(result.begin(), result.end());
        return result;
    }

private:
    int t[1001][1001]; // DP table for LCS
};
