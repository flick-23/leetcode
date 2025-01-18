class Solution {
public:
/*
*/
    int findProfit(int i, int txn, int n, vector<int>& prices, vector<vector<int>>& dp){
        if(i == n){
            return 0;
        }
        if(txn == 4){
            return 0;
        }
        if(dp[i][txn] != -1) return dp[i][txn];

        if(txn % 2 == 0){
            return dp[i][txn] = max(-prices[i] +findProfit(i+1,txn+1,n,prices,dp) ,
                                    0 +findProfit(i+1, txn, n, prices,dp));
        } 
        return dp[i][txn] = max(prices[i] + findProfit(i+1,txn+1,n,prices,dp),
                                        0+findProfit(i+1,txn,n,prices,dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>>dp(n,vector<int>(4,-1));
       return findProfit(0,0,n,prices,dp);
    }
};