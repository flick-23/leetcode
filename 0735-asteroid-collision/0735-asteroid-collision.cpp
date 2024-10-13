class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            bool destroyed = false;
            // Check only when one is moving right, the other
            // is moving left
            while (!st.empty() && st.top() > 0 && curr < 0) {
                int top = st.top();
                // Both are destroyed
                if (abs(top) == abs(curr)) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                // Current asteroid is destroyed
                else if (abs(top) > abs(curr)) {
                    destroyed = true;
                    break;
                }
                // Top asteroid is destroyed, so pop it from the stack
                else {
                    st.pop();
                }
            }

            if (!destroyed) {
                // Only push current asteroid if it wasn't destroyed
                st.push(curr);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};