class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(
            wordDict.begin(), wordDict.end()); // Store words for fast lookup
        int n = s.size();
        vector<bool> dp(n + 1,
                        false); // DP array: dp[i] means s[0:i] is breakable
        dp[0] = true;           // Base case: empty string is breakable

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // No need to check further, as we found a valid
                           // break
                }
            }
        }
        return dp[n];
    }
};