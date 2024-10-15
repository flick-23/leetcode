class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;
        vector<vector<string>>ans;
        for(string str: strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(str);
        }
        for(auto it : mpp){
            vector<string>temp = it.second;
            ans.push_back(temp);
        }
        return ans;
    }
};