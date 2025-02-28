class Solution {
private:
    int timer = 0;

private:
    void dfs(int node, int parent, vector<int>& visited, vector<int>& tin,
             vector<int>& low, vector<vector<int>>& bridges,
             vector<vector<int>>& adj) {
        visited[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if(it == parent) continue;
            if (visited[it] != 1) {
                dfs(it, node, visited, tin, low, bridges, adj);
                low[node] = min(low[node], low[it]);
                if (tin[node] < low[it]) {
                    bridges.push_back({it,node});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> visited(n,0), low(n), tin(n);
        vector<vector<int>> bridges;
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, -1, visited, tin, low, bridges, adj);
        return bridges;
    }
};