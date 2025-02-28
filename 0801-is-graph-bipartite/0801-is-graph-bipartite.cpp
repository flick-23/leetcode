class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph,
             vector<int>& visited) {
        visited[node] = color;
        for (auto it : graph[node]) {
            if (visited[it] == -1) {
                if (dfs(it, !color, graph, visited) == false)
                    return false;
            } else if (visited[it] == color)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, -1);
        for (int i = 0; i < V; i++) {
            if (visited[i] == -1) {
                if (!dfs(i, 0, graph, visited))
                    return false;
            }
        }
        return true;
    }
};