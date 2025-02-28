class Solution {
public:
    // Directions for movement: {up, right, down, left}
    static constexpr int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int rows, cols;

    int dfs(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int maxPath = 1; // At least the current cell itself
        for (const auto& dir : directions) {
            int x = i + dir[0], y = j + dir[1];

            // Check bounds and increasing condition
            if (x >= 0 && x < rows && y >= 0 && y < cols &&
                matrix[x][y] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(x, y, matrix, dp));
            }
        }

        return dp[i][j] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int maxLength = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxLength = max(maxLength, dfs(i, j, matrix, dp));
            }
        }

        return maxLength;
    }
};
