class Solution {
public:
    bool findPartition(int index, int target, vector<int>&nums, vector<vector<int>>&dp ){
        if(target == 0){
            return true;
        }
        if(index < 0){
            if(target == 0) return true;
            return false;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }

        int notPick = findPartition(index-1, target, nums, dp);
        int pick = 0;
        if(target - nums[index] >= 0)
            pick = findPartition(index-1, target - nums[index], nums, dp);
        dp[index][target] = pick || notPick;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0)
            return false;
        vector<vector<int>>dp(n, vector<int>(sum,-1));
        return findPartition(n-1,sum/2,nums,dp);
    }
};