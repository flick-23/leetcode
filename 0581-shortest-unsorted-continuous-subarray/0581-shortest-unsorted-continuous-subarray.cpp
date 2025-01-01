class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;

        // Identify the first inversion from the left
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                left = i;
                break;
            }
        }

        // If no inversion is found, the array is already sorted
        if (left == -1) return 0;

        // Identify the first inversion from the right
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] > nums[i]) {
                right = i;
                break;
            }
        }

        // Find the min and max in the unsorted subarray
        int subarrayMin = INT_MAX, subarrayMax = INT_MIN;
        for (int i = left; i <= right; i++) {
            subarrayMin = min(subarrayMin, nums[i]);
            subarrayMax = max(subarrayMax, nums[i]);
        }

        // Extend the left bound
        for (int i = 0; i <= left; i++) {
            if (nums[i] > subarrayMin) {
                left = i;
                break;
            }
        }

        // Extend the right bound
        for (int i = n - 1; i >= right; i--) {
            if (nums[i] < subarrayMax) {
                right = i;
                break;
            }
        }

        // Return the length of the unsorted subarray
        return right - left + 1;
    }
};
