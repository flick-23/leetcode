class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int sum = 0, maxLen = 0;
        mpp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] == 1 ? 1 : -1;
            if(mpp.find(sum) != mpp.end()){
                maxLen = max(maxLen, i - mpp[sum]);
            } else{
                mpp[sum] = i;
            }
        }
        return maxLen;
    }
};