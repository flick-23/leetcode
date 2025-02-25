class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> a;
        if(k>n){
            k = k - (k/n)*n;
        }
        long j=0,i=n-k;
        while(i<n){
            a.push_back(nums[i]);
            i++;
            j++;
        }
        i=0;
        while(j<n){
            a.push_back(nums[i]);
            j++;
            i++;
        }
        nums = a;
    }
};

