class Solution {
public:
    int isValid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        //left, right, bottom
        int dx[] = {1,1,1};
        int dy[] = {-1,1,0};
        int ans = INT_MAX;
        for(int i = 0; i < m; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 3; k++){
                    int row = dx[k] + i;
                    int col = dy[k] + j;
                    if(isValid(row,col,n,m)){
                        int sum = matrix[row][col] + dp[i][j];
                        dp[row][col] = min(dp[row][col], sum);
                    }
                }
            }
        }
        
        for(int it : dp[n-1]){
            ans = min(ans,it);
        }
        return ans;
    }
};