class Solution {
public:
    bool compare(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();
        if (n != m+1)
            return false;
        int first = 0;
        int second = 0;
        while(first < n){
            if(s1[first] == s2[second] && second < s2.size()){
                first++;
                second++;
            } else{
                first++;
            }
        }
        if(first == n && second == m)   return true;
        return false;
    }
    static bool comp(string& s1, string& s2) { return s1.size() < s2.size(); }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (compare(words[i], words[prev]) && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                }
                maxi = max(maxi, dp[i]);
            }
        }
        return maxi;
    }
};