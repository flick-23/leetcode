using info = tuple<int, short, short>; // (time, i, j)
const static int d[5] = {0, 1, 0, -1, 0};
class Solution {
public:
    inline static bool isOutside(short i, short j, short n, short m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1)
            return -1; // edge case

        short n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<info, vector<info>, greater<info>> pq;

        // Start at (0, 0) with time=0
        pq.emplace(0, 0, 0);
        time[0][0] = 0;
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            // reach the destination
            if (i == n - 1 && j == m - 1)
                return t;

            // Traverse all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                // minimum time to reach (r, s)
                int wait_time = grid[r][s];
                int next_time = t + 1;

                // Wait until we can step on this cell
                if (next_time < wait_time) {
                    int diff = wait_time - next_time;
                    next_time += (diff % 2 == 0) ? diff : diff + 1;
                }

                // update if this path having quicker time
                if (next_time < time[r][s]) {
                    time[r][s] = next_time;
                    pq.emplace(next_time, r, s);
                }
            }
        }

        return -1; // never reach
    }
};