class Solution {
public:
    vector<int> computeZ(string s, int& maxi){
        int n = s.length();
        vector<int>Z(n);
        int L = 0, R = 0;
        for(int i = 1; i < n; i++){
            if(i <= R){
                Z[i] = min(R-i+1, Z[i-L]);
            }
            while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]]){
                Z[i]++;
            }
            if(i + Z[i] - 1 > R){
                L = i;
                R = i + Z[i] - 1;
            }
            maxi = max(maxi,Z[i]);
        }
        return Z;
    }
    string longestPrefix(string s) {
        int n = s.length();
        
        int maxLen = 0;
        vector<int>Z = computeZ(s,maxLen);
        int index = 0;
        for(int i = 0; i < Z.size(); i++){
            if(Z[i] == s.size()-i){
                return s.substr(i);
                break;
            }
        }
        return "";
    }
};