class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<double,long long>freq;
        for(int r = 4; r <  n; r++){
            for(int p = 0, q = r-2; p < q - 1; p++){
                freq[(double)nums[p]/(double)nums[q]]++;
            }
            for(int s = r+2; s < n; s++){
                ans += freq[(double)nums[s]/(double)nums[r]];
            }
        }
        return ans;
    }
};