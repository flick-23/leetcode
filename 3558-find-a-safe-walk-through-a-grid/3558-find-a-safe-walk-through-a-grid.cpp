#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Directions for moving up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        // Priority queue for BFS: max-heap by remaining health
        priority_queue<tuple<int, int, int>> pq; // {remaining health, row, col}
        
        // Initial health after the first cell
        int initialHealth = health - grid[0][0];
        if (initialHealth <= 0) return false;
        
        // Visited set to track states (row, col, remaining health)
        vector<vector<int>> maxHealth(rows, vector<int>(cols, -1));
        maxHealth[0][0] = initialHealth;
        pq.emplace(initialHealth, 0, 0);
        
        while (!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();
            
            // If we've reached the bottom-right corner with positive health
            if (r == rows - 1 && c == cols - 1) {
                return true;
            }
            
            // Explore all four possible directions
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                // Check if the new position is within bounds
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int newHealth = h - grid[nr][nc];
                    
                    // Proceed if the new health is positive and improves the current state
                    if (newHealth > 0 && newHealth > maxHealth[nr][nc]) {
                        maxHealth[nr][nc] = newHealth;
                        pq.emplace(newHealth, nr, nc);
                    }
                }
            }
        }
        
        // If no valid path is found
        return false;
    }
};
