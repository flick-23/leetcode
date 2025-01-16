class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int i = 0,j = 0;
        bool flag = true;
        string ans = "";
        while(i < n && j < m){
            if(flag){
                ans += word1[i];
                i++;
            } else{
                ans += word2[j];
                j++;
            }
            flag = !flag;
        }
        while(i < n){
            ans += word1[i];
            i++;
        }
        while(j < m){
            ans += word2[j];
            j++;
        }
        return ans;
    }
};