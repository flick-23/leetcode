class Solution {
public:
    void dfs(int vtx, vector<int> adj[], vector<int>& visited) {
        visited[vtx] = 1;

        for (auto it : adj[vtx]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> visited(v, 0);
        int no_provinces = 0;

        vector<int> adj[v];

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                no_provinces++;
            }
        }

        return no_provinces;
    }
};