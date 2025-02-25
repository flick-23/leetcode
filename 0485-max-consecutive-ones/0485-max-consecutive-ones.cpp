class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int gm = 0, cm = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cm++;
            } else{
                cm = 0;
            }
            if(cm>gm){
                gm=cm;
            }
        }
        return gm;
    }
};