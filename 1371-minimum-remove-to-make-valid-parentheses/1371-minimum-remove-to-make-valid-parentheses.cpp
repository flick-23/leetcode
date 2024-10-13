class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(st.empty() && s[i] == ')'){
                s[i]='$';
            }
            else if(!st.empty() && s[i] == ')'){
                st.pop();
            }
            else if(s[i] == '('){
                st.push({'(',i});
            }
        }
        while(!st.empty()){
            s[st.top().second] = '$';
            st.pop();
        }
        for(int i = 0; i < n; i++){
            if(s[i] != '$')
                ans += s[i];
        }
        return ans;
    }
};