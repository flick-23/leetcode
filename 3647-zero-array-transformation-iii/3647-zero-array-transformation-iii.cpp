class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int queryIndex = 0;
        priority_queue<int> available; // Max-heap to store query ending indices
        priority_queue<int, vector<int>, greater<int>>
            running; // Min-heap for active queries

        sort(queries.begin(),
             queries.end()); // Sort queries by start index

        for (int i = 0; i < nums.size(); i++) {
            // Add all queries starting at index i
            while (queryIndex < queries.size() && queries[queryIndex][0] <= i) {
                available.push(queries[queryIndex][1]);
                queryIndex++;
            }

            // Remove expired queries
            while (!running.empty() && running.top() < i) {
                running.pop();
            }

            // Use queries to reduce nums[i] to 0
            while (nums[i] > running.size()) {
                if (available.empty() || available.top() < i) {
                    return -1; // Not enough queries
                }
                running.push(available.top());
                available.pop();
            }
        }

        return available.size(); // Number of queries we can remove
    }
};
