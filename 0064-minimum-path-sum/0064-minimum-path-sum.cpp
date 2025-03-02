class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[0][0] = grid[0][0];
        int top = 1e9, left = 1e9;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i-1>=0){
                    left= dp[i-1][j];  //left
                }
                if(j-1>=0){
                    top=dp[i][j-1];   //top
                }
                int cost = grid[i][j] + min(top,left);  //cell cost + min cost to arrive here, from either top or left
                dp[i][j] = min(dp[i][j],cost);  
            }
        }
        return dp[m-1][n-1];
    }
};