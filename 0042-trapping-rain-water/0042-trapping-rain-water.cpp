class Solution {
public:
    int trap(vector<int>& height) {
        int r = height.size()-1;
        int l = 0;
        int lmax = 0, rmax = height[r];
        int ans = 0;
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] < lmax){
                    ans += lmax - height[l];
                } else{
                    lmax = height[l];
                }
                l++;
            } else{
                if(height[r] < rmax){
                    ans += rmax - height[r];
                } else{
                    rmax = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};