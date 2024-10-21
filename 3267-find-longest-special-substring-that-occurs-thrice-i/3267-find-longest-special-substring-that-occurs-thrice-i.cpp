class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int>mpp;
        int n = s.length();
        for(int i = 0; i < n; i++){
            char ch = s[i];
            string str = "";
            for(int len = 1; len <= n; len++){
                str = s.substr(i,len);
                if(str == string(len,ch)){
                    mpp[str]++;
                }
            }
        }
        int ans = -1;
        for(auto it : mpp){
            if(it.second >=3){
                ans = max(ans,(int)it.first.length());
            }
        }
        return ans == -1 ? -1 : ans;
    }
};