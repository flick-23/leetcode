class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cost = grid[i][j];
                int top = 1e9, left = 1e9;
                if(i-1>=0){
                    left= dp[i-1][j];  //left
                }
                if(j-1>=0){
                    top=dp[i][j-1];   //top
                }
                cost += min(top,left);
                dp[i][j] = min(dp[i][j],cost);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};