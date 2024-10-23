class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mpp;
        string ans = "";
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans += string(it.first,it.second);
        }
        return ans;
    }
};