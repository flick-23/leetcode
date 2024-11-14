class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>left, end;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            left[nums[i]]++;
        }
        for(int i = 0; i < n; i++){
            int ele = nums[i];
            if(left[ele] == 0)
                continue;
            left[ele]--;
            if(end[ele-1] > 0){
                end[ele-1]--;
                end[ele]++;
            } else if(left[ele+1]>0 && left[ele+2] > 0){
                left[ele+1]--;
                left[ele+2]--;
                end[ele+2]++;
            } else{
                return false;
            }
        }
        return true;
    }
};