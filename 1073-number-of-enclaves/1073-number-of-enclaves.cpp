class Solution {
public:
//find the boundary 1's -> DFS the 1's connected to boundary one's. Mark them as visited.
//unvisited 1's in the matrix is the ans.
    void dfs(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid,int dx[], int dy[],int r, int c){
        visited[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            // cout<<"r:"<<nrow<<" c:"<<ncol<<endl;
            if(nrow>=0 && ncol>=0 && nrow<r && ncol<c && !visited[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,visited,grid,dx,dy,r,c);
                // cout<<"\n\n";
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int r = grid.size();
        int c = grid[0].size();
        int i,j,count=0;
        vector<vector<int>> visited(r, vector<int>(c, 0));
    
        for(i=0;i<c;i++){
            if(grid[0][i] == 1 && !visited[0][i]){
                dfs(0,i,visited,grid,dx,dy,r,c);
            }
            if(grid[r-1][i] == 1 && !visited[r-1][i]){
                dfs(r-1,i,visited,grid,dx,dy,r,c);
            }
        }
        for(i = 0; i < r; i++){
            if(grid[i][0] == 1 && !visited[i][0])
                dfs(i,0,visited,grid,dx,dy,r,c);
            if(grid[i][c-1] == 1 && !visited[i][c-1])
                dfs(i,c-1,visited,grid,dx,dy,r,c);
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                // cout<<grid[i][j]<<" ";
                if(!visited[i][j] && grid[i][j] == 1)
                    count++;
            }
            // cout<<endl;
        }
        return count;
    }
};