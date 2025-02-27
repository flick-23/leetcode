class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int maxTime = 0;
        vector<int>gaps(n+1);
        gaps[0] = startTime[0];
        for(int i = 1; i < n; i++){
            gaps[i]=startTime[i]-endTime[i-1];
        }
        gaps[n] = eventTime - endTime.back();
        int sum = 0;
        for(int i = 0; i <= k; i++){
            sum+= gaps[i];
        }
        maxTime = max(maxTime, sum);
        for(int i = k+1; i < gaps.size(); i++){
            sum += gaps[i];
            sum -= gaps[i-k-1];
            maxTime = max(maxTime, sum);
        }
        return maxTime;
    }
};