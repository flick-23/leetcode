class Solution {
public:
    string longestPalindrome(string s1) {
        int n = s1.length();
        if(n == 0)  return "";
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int maxLength = 1;
        int start = 0;

        //all substrings of length 1 are palindrome.
        for(int i = 0; i < n; i++){ 
            dp[i][i] = true;
        }
        //check substr's of len 2
        for(int i = 0; i < n; i++){
            if(s1[i] == s1[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }
        //check for subs of len >= 3
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;    //ending index of curr subs
                if(s1[i] == s1[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(len > maxLength){
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        return s1.substr(start,maxLength);
    }
};