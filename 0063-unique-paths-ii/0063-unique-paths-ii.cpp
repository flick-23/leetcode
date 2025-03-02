class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> grid(rows,vector<int>(cols,0));
        int i,j;
        if(obstacleGrid[rows-1][cols-1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        for(i=0;i<rows;i++){
            int count = 0;
            for(j=0;j<cols;j++){
                if(obstacleGrid[i][j] == 1){
                    grid[i][j] = -1;    
                    count++;
                }
            }
            if(count == cols)
                return 0;
        }
        grid[0][0] = 1;
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(j != cols-1 && grid[i][j+1] != -1 && grid[i][j] != -1){
                    grid[i][j+1]+=grid[i][j];
                }
                if(i != rows-1 && grid[i+1][j] != -1 && grid[i][j] != -1){
                    grid[i+1][j]+=grid[i][j];
                }
            }
        }
        return grid[rows-1][cols-1];
    }
};