class Solution {
public:
    int calcProfit(int i, int txn,int n, vector<int>&prices, vector<vector<int>>& dp){
        if(i >= n)  return 0;

        if(dp[i][txn] != -1) return dp[i][txn];

        if(txn % 2 == 0){
            int buyStock = -prices[i] + calcProfit(i+1,1,n,prices,dp); 
            int skip = 0 + calcProfit(i+1,0,n,prices,dp);
            return dp[i][txn] = max(buyStock, skip);
        } else{
            int sellStock = prices[i] + calcProfit(i+2,0,n,prices,dp); 
            int skip = 0 + calcProfit(i+1,1,n,prices,dp);
            return dp[i][txn] = max(sellStock, skip);
        } 
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return calcProfit(0,0,n,prices,dp);
    }
};