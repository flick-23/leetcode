class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        int sum = 0, ans = 0;
        prefix[0]=1;
        for(auto it : nums){
            sum += it;
            int compliment = sum - k;
            if(prefix[compliment]){
                ans += prefix[compliment];
            }
            prefix[sum]++;
        }
        return ans;
    }
};