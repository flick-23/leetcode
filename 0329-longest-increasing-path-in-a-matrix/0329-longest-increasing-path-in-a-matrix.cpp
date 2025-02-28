class Solution {
public:
    bool isValid(int i, int j, int row, int col) {
        return i >= 0 && j >= 0 && i < row && j < col;
    }
    int dfs(int i, int j, int n, int m, vector<vector<int>>& dp,
            vector<vector<int>>& matrix) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int maxPath = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (isValid(x, y, n, m)) {
                if (matrix[i][j] > matrix[x][y]) {
                    maxPath = max(1 + dfs(x, y, n, m, dp, matrix), maxPath);
                }
            }
        }
        return dp[i][j] = maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int ans = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, dfs(i, j, rows, cols, dp, matrix));
            }
        }
        return ans;
    }
};