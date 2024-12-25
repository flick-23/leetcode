class Solution {
public:
    const int MOD = (int)(1e9 + 7);
    vector<int>findNextSmaller(int n, vector<int>arr){
        vector<int>ans(n,n);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>findPrevSmaller(int n, vector<int>arr){
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nextSmaller = findNextSmaller(n,arr);
        vector<int>prevSmaller = findPrevSmaller(n,arr);
        int total = 0;
        for(int i = 0; i < n; i++){
            int nse = nextSmaller[i] - i;
            int pse = i - prevSmaller[i];
            total = (total+ (nse*pse*1ll*arr[i]) % MOD) % MOD;
        }
        return total;
    }
};