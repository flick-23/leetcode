class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int area, ans = 0;
        while(left < right){
            int w = right - left;
            int l = min(height[left],height[right]);
            int area = l * w;
            ans = max(area,ans);
            if(height[left] <= height[right]){
                left++;
            } else{
                right--;
            }
        }
        return ans;
    }
};