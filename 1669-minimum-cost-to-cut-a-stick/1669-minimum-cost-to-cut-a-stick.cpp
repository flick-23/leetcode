class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        //stick boundaries
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();    //total cuts including boundaries

        //DP[i][j] => Minimal cost to cut the stick between cuts[i] & cuts[j]
        vector<vector<int>>dp(m,vector<int>(m,0));
        //fill dp for increasing lengths of substick
        for(int len = 2; len < m; len++){
            //i is starting point of the segment
            for(int i = 0; i < m - len; i++){
                //j is ending point of segment
                int j = i + len;
                dp[i][j] = INT_MAX;
                //try every cut k b/w cuts[i] & cuts[j]
                //this will help to split the stick optimally
                for(int k = i + 1;  k < j; k++){
                    //cost to cut at cuts[k] = len of curr stick segment + cost of cutting left & right segments
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    //take the min cost of this segment
                    dp[i][j] = min(cost,dp[i][j]);
                }
            }
        }
        //the final result is stored in here, which shows min cost to cut stick from 0 to n
        return dp[0][m-1];
    }
};