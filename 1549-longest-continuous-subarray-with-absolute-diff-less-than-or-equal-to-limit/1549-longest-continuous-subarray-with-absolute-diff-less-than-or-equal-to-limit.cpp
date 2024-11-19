class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>maxque, minque;
        int n = nums.size();
        int i = 0, j = 0;
        int maxsize = 1;
        while(j < n){
            while(!maxque.empty() && nums[j] > maxque.back()){
                maxque.pop_back();
            }
            while(!minque.empty() && nums[j] < minque.back()){
                minque.pop_back();
            }
            maxque.push_back(nums[j]);
            minque.push_back(nums[j]);
            if(maxque.front() - minque.front() > limit){
                if(maxque.front() == nums[i])
                    maxque.pop_front();
                if(minque.front() == nums[i])
                    minque.pop_front();
                i++;
            }
            maxsize = max(maxsize, j-i+1);
            j++;
        }
        return maxsize;
    }
};