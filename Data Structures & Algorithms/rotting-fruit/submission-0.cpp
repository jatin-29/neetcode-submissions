class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Queue stores all initially rotten oranges
        queue<pair<int, int>> q;

        int freshCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();
            bool rottenFound = false;

            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                        rottenFound = true;
                    }
                }
            }

            if (rottenFound)
                minutes++;
        }

        // MISTAKE 1:
        // You were checking inside the while loop:
        // if(freshCount>0) return -1;
        // This returns after processing only one BFS level.
        // It should be checked AFTER BFS finishes.

        if (freshCount > 0)
            return -1;

        // MISTAKE 2:
        // You were returning minutes inside the while loop.
        // That also exits after the first level.
        // Return should be after the loop ends.

        return minutes;
    }
};