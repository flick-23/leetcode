class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Stores the in-degree (number of dependencies) for each course
        vector<int> indegree(numCourses);

        // Adjacency list representing course prerequisites
        vector<vector<int>> adj(numCourses);

        // Queue to store courses with no prerequisites (in-degree = 0)
        queue<int> q;

        // Counter to track how many courses can be completed
        int courseCount = 0;

        // Build the adjacency list and in-degree array
        for (int i = 0; i < prerequisites.size(); i++) {
            // Course that depends on prerequisite v
            int u = prerequisites[i][0];
            // Prerequisite course
            int v = prerequisites[i][1];
            // Add prerequisite v to course u's adjacency list
            adj[u].push_back(v);
            // Increase in-degree of course v (it has one more dependency)
            indegree[v]++;
        }

        // Find all courses that have no prerequisites (in-degree = 0)
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform a topological sort using Kahn’s algorithm (BFS approach)
        while (!q.empty()) {
            courseCount++;        // Process a course
            int node = q.front(); // Get the course from the queue
            q.pop();

            // Reduce the in-degree of all its dependent courses
            for (auto adjNode : adj[node]) {
                indegree[adjNode]--; // Remove the prerequisite dependency
                // If a course has no more prerequisites, add to queue
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        // If we were able to process all courses, return true; otherwise,
        // return false
        return courseCount == numCourses;
    }
};