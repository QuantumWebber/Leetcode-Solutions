class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of boundary
        if (r < 0 || r >= m || c < 0 || c >= n)
            return 1;

        // Water
        if (grid[r][c] == 0)
            return 1;

        // Already visited
        if (grid[r][c] == -1)
            return 0;

        // Mark visited
        grid[r][c] = -1;

        return dfs(grid, r - 1, c)
             + dfs(grid, r + 1, c)
             + dfs(grid, r, c - 1)
             + dfs(grid, r, c + 1);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1)
                    return dfs(grid, i, j);
            }
        }

        return 0;
    }
};