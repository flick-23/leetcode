class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int prev = INT_MIN, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = max((nums[i] - k), prev + 1);
            if (curr <= (nums[i] + k)) {
                ++ans;
                prev = curr;
            }
        }
        return ans;
    }
};