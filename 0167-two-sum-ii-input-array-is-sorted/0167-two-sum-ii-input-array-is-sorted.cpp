class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
         vector<int> A,ans;
        A=a;
        int n =a.size(),i;
        int left = 0, right = n-1;
        vector<int>x;
        while (left < right) {
            int sum = a[left] + a[right];
            if (sum == target) {
                x.push_back(a[left]);
                x.push_back(a[right]);
                break;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
        for(i=0;i<n || ans.size()<2;i++){
            if(x[0]==A[i]){
                ans.push_back(i+1);
                A[i]=INT_MIN;
            }
            else if(x[1]==A[i]){
                ans.push_back(i+1);
                A[i]=INT_MIN;
            }
        }
        return ans;
    }
};