class Solution {
public:
    int checkNeighbour(int node, int adjNode, vector<vector<int>>&graph){
        for(auto i : graph[adjNode]){
            if(i == node){
                return 0;
            }
        }
        return 1;
    }
    void dfs(int node, int &switches, vector<int>&visited, vector<vector<int>>& graph, vector<vector<int>>& adj){
        visited[node] = 1;
        for(auto adjNode : adj[node]){
            if(visited[adjNode] == 0){
                switches += checkNeighbour(node,adjNode,graph);
                dfs(adjNode, switches, visited, graph, adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<vector<int>>graph(n);
        vector<int>visited(n,0);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);  //original directed
            adj[u].push_back(v);    // undirected
            adj[v].push_back(u);
        }
        int switches = 0;
        dfs(0,switches,visited,graph,adj);
        return switches;
    }
};