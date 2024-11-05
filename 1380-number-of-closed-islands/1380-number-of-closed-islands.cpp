class Solution {
public:
    void waterify(vector<vector<int>>& grid, int row, int col, int r, int c) {
        if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == 1)
            return;

        grid[r][c] = 1;
        waterify(grid, row, col, r + 1, c);
        waterify(grid, row, col, r, c + 1);
        waterify(grid, row, col, r - 1, c);
        waterify(grid, row, col, r, c - 1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int c = 0; c < cols; c++) {
            waterify(grid, rows, cols, 0, c);
            waterify(grid, rows, cols, rows - 1, c);
        }

        for (int r = 0; r < rows; r++) {
            waterify(grid, rows, cols, r, 0);
            waterify(grid, rows, cols, r, cols - 1);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    waterify(grid, rows, cols, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
};