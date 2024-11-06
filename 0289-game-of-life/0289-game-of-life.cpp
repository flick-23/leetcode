class Solution {
public:
    int liveNeighbourCount(int x, int y, vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int row = x + i;
                int col = y + j;

                if ((i != 0 || j != 0) && row >= 0 && col >= 0 && row < n &&
                    col < m &&
                    (board[row][col] == 1 || board[row][col] == -2)) {
                    count++;
                }
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        // 0 to 1 => 2
        // 1 to 0 => -2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveCells = liveNeighbourCount(i, j, board);
                cout << liveCells << " ";
                if (board[i][j] == 1 || board[i][j] == -2) {
                    if (liveCells > 3) {
                        board[i][j] = -2;
                    } else if (liveCells >= 2 && liveCells <= 3) {
                        board[i][j] = 1;
                    } else {
                        board[i][j] = -2;
                    }
                } else if (board[i][j] == 0 || board[i][j] == 2) {
                    if (liveCells == 3) {
                        board[i][j] = 2;
                    }
                }
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;
                if (board[i][j] == -2)
                    board[i][j] = 0;
            }
        }
    }
};