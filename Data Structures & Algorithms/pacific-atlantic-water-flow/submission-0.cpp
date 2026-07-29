class Solution {
private:
    int rows, cols;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        if (visited[r][c])
            return;

        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, visited);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        if (heights.empty() || heights[0].empty())
            return {};

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific (top row)
        for (int c = 0; c < cols; c++)
            dfs(0, c, heights, pacific);

        // Pacific (left column)
        for (int r = 0; r < rows; r++)
            dfs(r, 0, heights, pacific);

        // Atlantic (bottom row)
        for (int c = 0; c < cols; c++)
            dfs(rows - 1, c, heights, atlantic);

        // Atlantic (right column)
        for (int r = 0; r < rows; r++)
            dfs(r, cols - 1, heights, atlantic);

        vector<vector<int>> result;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};