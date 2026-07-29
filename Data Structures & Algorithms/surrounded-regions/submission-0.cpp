class Solution {

private:
    void dfs(vector<vector<char>>& board, int r, int c) {

        int m = board.size();
        int n = board[0].size();

        if (r < 0 || c < 0 || r >= m || c >= n)
            return;

        

        if (board[r][c] != 'O')
            return;

        board[r][c] = 'S';

        dfs(board, r - 1, c);
        dfs(board, r + 1, c);
        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();

        if (n == 0)
            return;

        int m = board[0].size();

        // Top boundary
        for (int j = 0; j < m; j++)
            dfs(board, 0, j);

        // Bottom boundary
        for (int j = 0; j < m; j++)
            dfs(board, n - 1, j);

       

        for (int i = 0; i < n; i++)
            dfs(board, i, 0);

       

        for (int i = 0; i < n; i++)
            dfs(board, i, m - 1);

        

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};