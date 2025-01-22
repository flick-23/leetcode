/*
This solution uses a hash map to count the frequency of each element in O(n), followed by a bucket sort approach to organize elements by their frequencies. The bucket array is indexed by frequency, where each bucket contains the elements that appear that many times in the input array. By iterating over the bucket array in reverse (from highest frequency to lowest), we efficiently collect the top k frequent elements in O(n) without needing to sort. This approach reduces the time complexity from O(n \log n) (using a priority queue) to O(n).
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        //num : freq
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        //add the nums based on the freq, where freq is the index
        vector<vector<int>>bucket(n+1);
        for(auto&[num, freq] : mpp){
            bucket[freq].push_back(num);
        }
        for(int i = bucket.size()-1; i >= 0 && ans.size() < k; i--){
            for(auto num : bucket[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    break;
                }
            }
        }
        return ans;
    }
};