class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i = 0; i < n; i++){
            if(i > maxIndex){
                return false;
            }
            maxIndex = max(maxIndex, nums[i]+i);
        }
        return true;
    }
};