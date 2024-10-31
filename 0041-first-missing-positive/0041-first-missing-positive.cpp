class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i;
        unordered_map<int,int>mpp;
        for(i = 0; i < n; i++){
            mpp[nums[i]] = i;
        }
        for(int i = 0; i < n+n; i++){
            if(mpp.find(i+1) == mpp.end()){
                return i+1;
            }
        }
        return 0;
    }
};