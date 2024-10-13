class Solution {
public:
    int findMaxCash(int index, vector<int>& nums, vector<int>&dp){
        if(index < 0){
            return 0;
        }
        if(dp[index] != -1) return dp[index];

        int notPick = findMaxCash(index-1,nums,dp);
        int pick = nums[index]+findMaxCash(index-2,nums,dp);
        
        return dp[index] = max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int>first, last;
        for(int i = 0; i < n; i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                last.push_back(nums[i]);
            }
        }
        vector<int>dp1(first.size(),-1);
        vector<int>dp2(last.size(),-1);
        int f = findMaxCash(first.size()-1,first,dp1);
        int l = findMaxCash(last.size()-1,last,dp2);
        return max(f, l);
    }
};