class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        vector<int> dx = {0, 0, 1, -1}; // Right, Left, Down, Up
        vector<int> dy = {1, -1, 0, 0};

        pq.push({0, {0, 0}}); // {cost, {i, j}}
        cost[0][0] = 0;

        while (!pq.empty()) {
            auto [currCost, cell] = pq.top();
            auto [i, j] = cell;
            pq.pop();

            if (currCost > cost[i][j])
                continue; // Skip outdated paths

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                    continue;

                int newCost = cost[i][j] + (d + 1 != grid[i][j]);

                if (newCost < cost[ni][nj]) {
                    cost[ni][nj] = newCost;
                    pq.push({newCost, {ni, nj}});
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
