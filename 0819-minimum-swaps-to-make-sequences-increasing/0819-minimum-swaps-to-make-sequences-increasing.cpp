class Solution {
public:
    int solve(vector<int>&nums1, vector<int>&nums2, vector<vector<int>>& dp, int index, int isSwapped){
        if(index >= nums1.size())
            return 0;

        if(dp[index][isSwapped] != -1)
            return dp[index][isSwapped];

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        int minSwap = INT_MAX;
        if(isSwapped)
            swap(prev1, prev2);
        
        if(nums1[index] > prev1 && nums2[index] > prev2){
            minSwap = solve(nums1, nums2, dp, index+1, 0);
        }
        if(nums1[index] > prev2 && nums2[index] > prev1){
            minSwap = min(minSwap, 1 + solve(nums1, nums2, dp, index+1, 1));
        }
        return dp[index][isSwapped] = minSwap;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        int n = nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(nums1, nums2,dp,1,0);
    }
};