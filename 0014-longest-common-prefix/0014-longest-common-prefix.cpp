class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans = "";
        int len = str.size();
        for (int j = 0; j < str[0].length(); j++) {
            int flag = 0;
            char mainStringChar = str[0][j];
            for (int i = 1; i < len; i++) {
                char checkStringChar = str[i][j];
                if (mainStringChar != checkStringChar) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                ans += mainStringChar;
            else
                break;
        }
        return ans;
    }
};