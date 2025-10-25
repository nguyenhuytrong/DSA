#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> adj;  // adjacency list
    vector<bool> visited;
    int m, n;

    void DFS(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) DFS(v);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        int totalNodes = m * n;

        adj.assign(totalNodes, {});
        visited.assign(totalNodes, false);

        // Directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Step 1: Build adjacency list
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    int id = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                            int nid = ni * n + nj;
                            adj[id].push_back(nid);
                        }
                    }
                }
            }
        }

        // Step 2: Count connected components (DFS)
        int count = 0;
        for (int i = 0; i < totalNodes; i++) {
            if (!visited[i]) {
                // check if it's land
                int row = i / n, col = i % n;
                if (grid[row][col] == '1') {
                    DFS(i);
                    count++;
                }
            }
        }

        return count;
    }
};
