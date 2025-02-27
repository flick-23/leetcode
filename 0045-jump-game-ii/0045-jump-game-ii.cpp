class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int currentEnd = 0, farthest = 0, jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, nums[i] + i);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                if (farthest >= n - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};