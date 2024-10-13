class Solution {
public:
    //smaller
    vector<long long int>nextSmaller(int n, vector<int>arr){
        vector<long long int>ans(n,n);
        stack<long long int>st;
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
    vector<long long int>prevSmaller(int n, vector<int>arr){
        vector<long long int>ans(n,-1);
        stack<long long int>st;
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
    long long int findSmallest(int n, vector<int>arr){
        long long int sum = 0;
        vector<long long int>next = nextSmaller(n, arr);
        vector<long long int>prev = prevSmaller(n, arr);
        for(int i = 0; i < n; i++){
            long long int nse = next[i] - i;
            long long int pse = i - prev[i];
            sum += (nse * pse * arr[i]);
        }
        return sum;
    }
    //greater
    vector<long long int>nextLargest(int n, vector<int>arr){
        vector<long long int>ans(n,n);
        stack<long long int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<long long int>prevLargest(int n, vector<int>arr){
        vector<long long int>ans(n,-1);
        stack<long long int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long int findLargest(int n, vector<int>arr){
        long long int sum = 0;
        vector<long long int>next = nextLargest(n, arr);
        vector<long long int>prev = prevLargest(n, arr);
        for(int i = 0; i < n; i++){
            long long int nge = next[i] - i;
            long long int pge = i - prev[i];
            sum += (nge * pge * arr[i]);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long int smallest = findSmallest(n, nums);
        long long int largest = findLargest(n,nums);
        long long int total = largest-smallest;
        return total;
    }
};