#include<bits/stdc++.h>
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>>mpp;
        int n = s.length();
        vector<int>ans;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(mpp.count(ch) == 0){
                mpp.insert({ch,{i,i}});
            } else{
                mpp[ch].second = i;
            }
        }
        int count = 0;
        int left = 0, right = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            int start = mpp[ch].first;
            int end = mpp[ch].second;
            if(i == 0){
                right = end;
                continue;
            }
            if(start >= left && end <= right){
                continue;
            }
            else if(start >= left && end > right && start<right){
                right = end;
            } else if(start > right){
                ans.push_back(right-left+1);
                left = start;
                right = end;
            }
        }
        ans.push_back(right-left+1);
        return ans;
    }
};