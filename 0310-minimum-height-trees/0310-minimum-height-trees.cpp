class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)  return {0};
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        int remainingNodes = n;
        while(remainingNodes > 2){
            int leafCount = q.size();
            remainingNodes -= leafCount;
            for(int i = 0; i < leafCount; i++){
                int node = q.front();
                q.pop();
                for(int adjNode : adj[node]){
                    degree[adjNode]--;
                    if(degree[adjNode] == 1){
                        q.push(adjNode);
                    }
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};