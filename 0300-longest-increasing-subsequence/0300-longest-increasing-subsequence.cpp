class Solution {
public:
    int f(int i, int j, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size()) return 0;

        if(dp[i][j+1] != -1)    return dp[i][j+1];

        int notPick = 0 + f(i+1,j,prices,dp);
        
        int pick = 0;
        if(j == -1 || prices[i]>prices[j]){
            pick = 1 + f(i+1,i,prices,dp);
        }
        return dp[i][j+1] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};