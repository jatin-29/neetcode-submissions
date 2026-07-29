class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {

        int row = grid.size();
        int col = grid[0].size();

        // Out of boundary
        if (i < 0 || i >= row || j < 0 || j >= col)
            return 1;

        // Water contributes to perimeter
        if (grid[i][j] == 0)
            return 1;

        // Already visited
        if (grid[i][j] == -1)
            return 0;

        // Mark visited
        grid[i][j] = -1;

        return dfs(grid, i + 1, j)
             + dfs(grid, i - 1, j)
             + dfs(grid, i, j + 1)
             + dfs(grid, i, j - 1);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }
};