class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int i = 0, n = s.length();
        string ans = "";
        int j = 0, ch = 0;
        vector<vector<string>>str(n,vector<string>(n,"-"));
        while(ch < n){
            while(i < numRows && j < n && ch < n){
                // cout<<"i:"<<i<<", j:"<<j<<endl;
                str[i][j] = s[ch];
                i++;
                ch++;
            }
            j++;
            i-=2;
            while(i >= 0 && j < n && ch < n){
                // cout<<"i:"<<i<<", j:"<<j<<endl;
                str[i][j] = s[ch];
                i--;
                j++;
                ch++;
            }
            i+=2;
            j--;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(str[i][j] != "-"){
                    ans += str[i][j];
                }
            }
        }
        return ans;
    }
};