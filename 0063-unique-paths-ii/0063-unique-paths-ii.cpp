class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        // If start or end cell has obstacle, return 0
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<int> dp(n, 0);
        dp[0] = 1; // Base case: There's one way to start at (0,0)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Obstacle: no paths through this cell
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Sum of paths from left and top
                }
            }
        }
        return dp[n - 1]; // Return last column's value
    }
};
