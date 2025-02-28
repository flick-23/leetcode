class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        queue<int>q;
        int courseCount = 0;
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            courseCount++;
            int node = q.front();
            q.pop();
            for(auto adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
       
        return courseCount == numCourses;
    }
};