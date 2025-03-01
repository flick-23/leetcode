class Solution {
public:
    void solve(int open, int close, int n, string str, vector<string>& ans){
        if(n == open && n == close){
                ans.push_back(str);
        }
        if(open < n){
            solve(open+1, close, n, str+'(', ans);
        }
        if(close<open){
            solve(open, close+1, n, str+')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};