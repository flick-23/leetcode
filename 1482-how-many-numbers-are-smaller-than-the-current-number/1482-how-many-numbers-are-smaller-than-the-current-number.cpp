class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr = nums;
        sort(nums.begin(), nums.end());
        int count = 1;
        vector<int>duplicates(n,0);
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                int j = i;
                while(j < n && nums[j] == nums[j-1]){
                    duplicates[j] = count++;
                    j++;
                }
                i = j - 1;
                count = 1;
            }
        }
        for(int i = 0; i < n; i++){
            mpp[nums[i]] = i - duplicates[i];
        }
        for(int i = 0; i < n; i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};