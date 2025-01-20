class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), i;
        if(n == 2){
            if(nums[0]<nums[1])
                return 1;
            return 0;
        }
        for(i=0;i<n;i++){
            if(i == 0 && i+1 < n && nums[i+1]<nums[i])
                return i;
            if(i>0 && i+1 < n && nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                return i;
            }
            if(i-1 > 0 && i == n-1 && nums[i-1] < nums[i]){
                return i;
            }
        }
        return 0;
    }
};