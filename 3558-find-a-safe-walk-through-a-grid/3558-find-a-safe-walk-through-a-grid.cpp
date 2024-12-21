#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Directions for moving up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        // Initial health after the first cell
        int initialHealth = health - grid[0][0];
        if (initialHealth <= 0) return false;
        
        // Queue for BFS: (row, col, remaining health)
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, initialHealth);
        
        // Visited array to track (row, col, remaining health)
        vector<vector<vector<bool>>> visited(rows, vector<vector<bool>>(cols, vector<bool>(health + 1, false)));
        visited[0][0][initialHealth] = true;
        
        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();
            
            // If we've reached the bottom-right corner with positive health
            if (r == rows - 1 && c == cols - 1 && h > 0) {
                return true;
            }
            
            // Explore all four possible directions
            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                // Check if the new position is within bounds
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int newHealth = h - grid[nr][nc];
                    
                    // Proceed if the new health is positive and the state hasn't been visited
                    if (newHealth > 0 && !visited[nr][nc][newHealth]) {
                        visited[nr][nc][newHealth] = true;
                        q.emplace(nr, nc, newHealth);
                    }
                }
            }
        }
        
        // If no valid path is found
        return false;
    }
};
