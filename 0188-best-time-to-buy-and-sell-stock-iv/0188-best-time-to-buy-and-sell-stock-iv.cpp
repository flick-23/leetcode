class Solution {
public:
    int solve(int i, int txn, int k, int n, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][txn] != -1) {
            return dp[i][txn];
        }
        if (txn == k) {
            return 0;
        }
        if (txn % 2 == 0) {
            return dp[i][txn] =
                       max(-prices[i] + solve(i + 1, txn + 1, k, n, prices, dp),
                           solve(i + 1, txn, k, n, prices, dp));
        }
        return dp[i][txn] = max(prices[i] + solve(i + 1, txn + 1, k, n, prices, dp),
                   solve(i + 1, txn, k, n, prices, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>((2*k)+1, -1));
        return solve(0, 0, 2*k, n, prices, dp);
    }
};