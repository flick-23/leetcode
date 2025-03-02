class Solution {
public:
    // int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    //     if (i < 0) {
    //         // string 1 is over. - need j+1 steps to match
    //         return j + 1;
    //     }
    //     if (j < 0) {
    //         return i + 1;
    //     }
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (s1[i] == s2[j]) {
    //         return dp[i][j] = 0 + solve(i - 1, j - 1, s1, s2, dp);
    //     } else {
    //         return dp[i][j] = min(1 + solve(i, j - 1, s1, s2, dp),
    //                               min(1 + solve(i - 1, j, s1, s2, dp),
    //                                   1 + solve(i - 1, j - 1, s1, s2, dp)));
    //     }
    // }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill base cases
        for (int i = 0; i <= m; i++)
            dp[i][0] = i; // Convert word1[0:i] to empty word2 (deletions)
        for (int j = 0; j <= n; j++)
            dp[0][j] = j; // Convert empty word1 to word2[0:j] (insertions)

        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // No change needed
                } else {
                    dp[i][j] = min({
                        dp[i - 1][j] + 1,    // Delete
                        dp[i][j - 1] + 1,    // Insert
                        dp[i - 1][j - 1] + 1 // Replace
                    });
                }
            }
        }

        return dp[m][n];
    }
};