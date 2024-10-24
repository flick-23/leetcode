class Solution {
public:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        queue<int>q;
        q.push(adj[node][0]);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = 1;
            for(int it : adj[node]){
                if(visited[it] == 0)
                    q.push(it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        int i,j;
        for(i = 0; i < n; i++){
            for(j = 0; j < isConnected[i].size(); j++){
                if(isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }
        int provinces = 0;
        for(i = 0; i < n; i++){
            if(visited[i] == 0){
                provinces++;
                bfs(i,adj,visited);
            }
        }
        return provinces;
    }
};