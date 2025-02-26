class Solution {
public:
    void dfs(int node, int n, vector<int>& visited, vector<vector<int>>& rooms) {
        visited[node] = 1;
        for (auto adjNode : rooms[node]) {
            if (visited[adjNode] == 0) {
                dfs(adjNode, n, visited, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        
        dfs(0, n, visited, rooms);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                return false;
            }
        }
        return true;
    }
};