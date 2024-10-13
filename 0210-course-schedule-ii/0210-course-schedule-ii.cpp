class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        vector<int>s;
        queue<int>q;
        int i;
        //make adj matx
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //calculate indegree
        for(i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        //push 0 indegree items in the queue
        for(i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        //process q for 0 indegree items and add them to the answer
        while(!q.empty()){
            int node = q.front();
            s.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        if(s.size() == numCourses)
            return s;

        return {};
    }
};