class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        // Build the graph and calculate indegrees
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Topological sort using a queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<vector<int>> freq(n, vector<int>(26, 0)); // Frequency table: node x color
        int processed = 0, maxColorValue = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;

            // Update the frequency of the current node's color
            int color = colors[node] - 'a';
            freq[node][color]++;
            maxColorValue = max(maxColorValue, freq[node][color]);

            // Propagate to neighbors
            for (int neighbor : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    freq[neighbor][c] = max(freq[neighbor][c], freq[node][c]);
                }

                // Decrease indegree and add to queue if it becomes 0
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If not all nodes were processed, there's a cycle
        if (processed != n) {
            return -1;
        }

        return maxColorValue;
    }
};
