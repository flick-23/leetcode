class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int min = INT_MAX;
        int max=0,i;
        for(i=0;i<n;i++){
            if(a[i]<min)
                min = a[i];
            if(a[i]-min > max)
                max = a[i]-min;
        }
        return max;
    }
};