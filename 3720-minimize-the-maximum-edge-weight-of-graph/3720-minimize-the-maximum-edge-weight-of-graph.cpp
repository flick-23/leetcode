class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>visited(n,0);
        int minW = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[v].push_back({w,u});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        //weight, node
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it[1];
            int weight = it[0];
            if(visited[node] == 1){
                continue;
            }
            visited[node] = 1;
            minW = max(minW, weight);
            for(auto adjNode : adj[node]){
                int w = adjNode.first;
                int nextNode = adjNode.second;
                if (visited[nextNode] == 0) {
                    pq.push({max(weight, w), nextNode});
                }
            }
        }
        for(auto it : visited){
            if(it == 0)
                return -1;
        }
        return minW;
    }
};