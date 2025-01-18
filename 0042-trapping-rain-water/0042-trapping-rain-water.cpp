class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i, j;
        vector<int> left(n, 0), right(n, 0);
        int maxi = height[0];
        for (i = 0; i < n; i++) {
            maxi = max(height[i], maxi);
            left[i] = maxi;
        }
        maxi = height[n-1];
        for (i = n-1; i >= 0; i--) {
            maxi = max(height[i], maxi);
            right[i] = maxi;
        }
        int ans = 0;
        for (i = 0; i < n; i++) {
            int minH = min(left[i], right[i]);
            ans += minH - height[i];
        }
        return ans;
    }
};