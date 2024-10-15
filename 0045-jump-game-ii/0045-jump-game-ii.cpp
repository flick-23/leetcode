class Solution {
public:
    int solve(int i, int jump, vector<int>&nums, vector<vector<int>>& dp){
        if(i>= nums.size()-1) return jump;
        if(dp[i][jump] != -1) return dp[i][jump];
        int mini = INT_MAX;
        for(int j = 1; j <= nums[i]; j++){
            mini = min(mini,solve(i+j,jump+1,nums,dp));
        }
        return dp[i][jump] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0, maxi = 0, jumps = 0;
        while(right < n-1){
            maxi = 0;
            for(int i = left; i <= right; i++){
                maxi = max(maxi, nums[i]+i);
            }
            left = right+1;
            jumps++;
            right = maxi;
        }
        return jumps;
    }
};