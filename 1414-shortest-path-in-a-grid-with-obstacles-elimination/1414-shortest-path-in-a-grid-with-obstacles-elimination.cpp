class Solution {
public:
    struct State {
        int x, y, steps, remainingK;
    };

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // If grid size is 1x1, no need to process further
        if (n == 1 && m == 1) return 0;

        // 3D visited array to track states (x, y, remainingK)
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        // BFS queue: store the current state (x, y, steps, remainingK)
        queue<State> q;
        q.push({0, 0, 0, k});
        visited[0][0][k] = 1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            int x = curr.x;
            int y = curr.y;
            int steps = curr.steps;
            int remainingK = curr.remainingK;

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Check if the new position is valid
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newK = remainingK - grid[nx][ny]; // Subtract 1 if obstacle
                    if (newK >= 0 && !visited[nx][ny][newK]) {
                        // If we reached the destination, return the steps
                        if (nx == n - 1 && ny == m - 1) return steps + 1;

                        // Mark as visited and push to queue
                        visited[nx][ny][newK] = 1;
                        q.push({nx, ny, steps + 1, newK});
                    }
                }
            }
        }

        // If we exhaust the BFS queue without reaching the destination
        return -1;
    }
};
