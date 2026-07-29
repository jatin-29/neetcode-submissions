class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // sirf UPAR check karo — row se niche sab khaali hai

        // vertical
        for (int i = row - 1; i >= 0; --i) {
            if (board[i][col] == 'Q') return false;
        }

        // left diagonal (upar-baayen)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // right diagonal (upar-daayen)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nQueen(vector<string>& board, int row, int n, int& count) {
        if (row == n) {
            ++count;              // board push karne ki jagah bas ginti
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';           // MARK
                nQueen(board, row + 1, n, count); // RECURSE
                board[row][j] = '.';           // RESTORE
            }
        }
    }

public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;
        nQueen(board, 0, n, count);
        return count;
    }
};