class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by start time
        sort(events.begin(), events.end());

        int maxVal = 0, result = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& event : events) {
            int start = event[0], end = event[1], value = event[2];

            // Remove events that end before the current event starts
            while (!pq.empty() && pq.top().first < start) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            // Update max result (best previous + current event)
            result = max(result, maxVal + value);

            // Store current event in the priority queue
            pq.push({end, value});
        }

        return result;
    }
};
