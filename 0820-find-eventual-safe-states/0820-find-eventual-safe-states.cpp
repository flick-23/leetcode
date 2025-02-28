class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //reverse the graph direction - topo sort and whatever we have left in the stack are the nodes that are safe nodes
        int V = graph.size();
        int i;
        vector<vector<int>>adj(V);
        //reverse the nodes
        for(i = 0; i < V; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
            }
        }
        vector<int>indegree(V,0);
        vector<int>ans;
        queue<int>q;
        for(i = 0; i < V; i++){
            for(auto it : adj[i])
                indegree[it]++;
        }
        for(i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};