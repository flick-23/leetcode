class Solution {
public:
    bool isValid(int x, int y, int rows, int cols) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
    // void bfs(int i, int j, vector<vector<char>>& grid, int n, int m){
    //     queue<pair<int,int>>q;
    //     q.push({i,j});
    //     while(!q.empty()){
    //         auto it = q.front();
    //         q.pop();
    //         int x = it.first;
    //         int y = it.second;
    //         grid[x][y] = '0';
    //         int dx[] = {-1,0,1,0};
    //         int dy[] = {0,1,0,-1};
    //         for(int itr = 0; itr < 4; itr++){
    //             int nx = dx[itr]+x;
    //             int ny = dy[itr]+y;
    //             if(isValid(nx,ny,n,m)){
    //                 if(grid[nx][ny] == '1'){
    //                     q.push({nx,ny});
    //                 }
    //             }
    //         }
    //     }
    // }
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        // Boundary conditions and if it's water ('0')
        if (!isValid(i, j, n, m) || grid[i][j] == '0')
            return;

        // Mark the current cell as visited (turn '1' into '0')
        grid[i][j] = '0';

        // Explore all 4 possible directions
        int dx[] = {-1, 1, 0, 0}; // Up, Down, Left, Right
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            dfs(ni, nj, grid, n, m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i, j = 0;
        int count = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};