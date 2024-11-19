class Solution {
public:
    int subArrayPartitions(int n, int maxSum, vector<int>& nums){
        int sum = 0, parts = 1;
        for(int i = 0; i < n; i++){
            if(sum+nums[i] > maxSum){
                sum = nums[i];
                parts++;
            } else{
                sum += nums[i];
            }
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        for(int i = 0; i < n; i++){
            low = max(low,nums[i]);
            high += nums[i];
        }
        while(low <= high){
            int mid = (low+high)/2;
            int partitions = subArrayPartitions(n,mid,nums);
            if(partitions <= k){
                high = mid - 1;
            } else{
                low = mid + 1;
            }
        }
        return low;
    }
};