class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        vector<int>dp(n,1); // Initialize LIS length for each index as 1
        for(int i = 1; i < n; i++){      // Traverse all elements
            for(int j = 0; j < i; j++){     // Check all previous elements
                if(nums[j] < nums[i])       // Can nums[i] extend LIS ending at j?
                    dp[i] = max(dp[i], dp[j]+1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};