class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int i = 0, j = 0;
        while(i < nums1.size()-n && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i++]);
            } else{
                ans.push_back(nums2[j++]);
            }
        }
        while(i < nums1.size()-n){
            ans.push_back(nums1[i++]);
        }
        while(j < nums2.size()){
            ans.push_back(nums2[j++]);
        }
        nums1 = ans;
    }
};