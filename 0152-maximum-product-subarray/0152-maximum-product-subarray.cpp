class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cm =1, gm = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            cm *= nums[i];
            gm = max(cm,gm);
            if(cm == 0){
                cm = 1;
            }
        }
        cm = 1;
        for(int i = nums.size()-1; i>=0; i--){
            cm *= nums[i];
            gm = max(cm,gm);
            if(cm == 0)
                cm = 1;
        }
        return gm;
    }
};