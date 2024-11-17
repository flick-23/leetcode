class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int index, int abs, int late, int n,
              vector<vector<vector<int>>>& dp) {
        if (index >= n) {
            return 1;
        }
        if (dp[index][abs][late] != -1) {
            return dp[index][abs][late];
        }
        int ans = 0;
        if (abs < 1) {
            ans =
                ((ans % MOD) + solve(index + 1, abs + 1, 0, n, dp) % MOD) % MOD;
        }
        if (late < 2) {
            ans = ((ans % MOD) + solve(index + 1, abs, late + 1, n, dp) % MOD) %
                  MOD;
        }
        ans = ((ans % MOD) + solve(index + 1, abs, 0, n, dp) % MOD) % MOD;
        return dp[index][abs][late] = ans;
    }
    int checkRecord(int n) {
        int abs = 0;
        int late = 0;
        int index = 0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3, -1)));
        return solve(index, abs, late, n, dp);
    }
};