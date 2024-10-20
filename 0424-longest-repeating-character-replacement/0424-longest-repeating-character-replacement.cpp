class Solution {
public:
    int getCharLen(string s, int k, char ch, int n){
        int i = 0, j = 0;
        int maxi = 0;
        while(j < n){
            if(s[j++] != ch){
                k--;
            }
            while(k < 0){
                if(s[i++] != ch){
                    k++;
                }
            }
            maxi = max(maxi, j-i);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++){
            int len = getCharLen(s,k,ch, n);
            ans = max(ans,len);
        }
        return ans;
    }
};