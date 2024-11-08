class Solution {
public:
    vector<int> ans, count;

    void dfs1(int node, int parent, vector<vector<int>>& adj) {
        count[node] = 1;
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            dfs1(neighbor, node, adj);
            count[node] += count[neighbor];
            ans[node] += ans[neighbor] + count[neighbor];
        }
    }

    void dfs2(int node, int parent, vector<vector<int>>& adj, int n) {
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            // Re-root the tree at neighbor
            ans[neighbor] = ans[node] - count[neighbor] + (n - count[neighbor]);
            dfs2(neighbor, node, adj, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        ans.resize(n, 0);
        count.resize(n, 0);

        // Build the adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // First DFS to calculate initial distances from the root (node 0)
        dfs1(0, -1, adj);

        // Second DFS to propagate the answers to all nodes
        dfs2(0, -1, adj, n);

        return ans;
    }
};