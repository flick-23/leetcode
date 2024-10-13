class Solution {
public:
    void dfs(int parent, int node, vector<vector<int>>& adj,
             vector<vector<int>>& ans, vector<bool>& visited) {
                
        if (parent != node) {
            ans[node].push_back(parent);
        }

        visited[node] = true;

        for (int child : adj[node]) {
            if (!visited[child]) {
                dfs(parent, child, adj, ans, visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            dfs(i, i, adj, ans, visited);
        }
        return ans;
    }
};