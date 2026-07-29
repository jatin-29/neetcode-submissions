class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // NOTE: horizontal check ki zaroorat nahi — current row abhi khaali hai
        // Sirf UPAR ki taraf check karo, kyunki niche kuch rakha hi nahi gaya

        // vertical (upar)
        for (int i = row - 1; i >= 0; --i) {
            if (board[i][col] == 'Q') return false;
        }

        // left diagonal (upar-baayen)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;    // <-- board[i][j], not board[row][col]
        }

        // right diagonal (upar-daayen)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;    // <-- yahi bug tha
        }

        return true;
    }

    void nQueen(vector<string>& board, int row, int n,
                vector<vector<string>>& ans) {       // <-- & lagana zaroori
        if (row == n) {
            ans.push_back(board);                    // <-- no braces
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';                 // <-- = not ==
                nQueen(board, row + 1, n, ans);      // <-- row+1
                board[row][j] = '.';                 // <-- '.' not "."
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));     // <-- '.' char literal
        vector<vector<string>> ans;
        nQueen(board, 0, n, ans);
        return ans;
    }
};