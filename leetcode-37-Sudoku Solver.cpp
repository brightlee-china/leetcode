class Solution {
public:
    bool valid(vector<vector<char >>&board, int r, int c, char num) {
        for (int i = 0; i < 9; i ++) {
            if (board[i][c] == num)
                return false;
        }
        
        for (int i = 0; i < 9; i ++) {
            if (board[r][i] == num) 
                return false;
        }
        
        int row = r / 3 * 3;
        int col = c / 3 * 3;
        for (int i = row; i < row + 3; i ++) {
            for (int j = col; j < col + 3; j ++) {
                if (board[i][j] == num)
                    return false;
            }
        }
        
        return true;
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solve(board, i + 1, 0);
        if (board[i][j] != '.')
            return solve(board, i, j + 1);
        
        for (char num = '1'; num <= '9'; num ++) {
            if (valid(board, i, j, num)) {
                board[i][j] = num;
                if (solve(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};