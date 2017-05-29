class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int valid_r[9][9] = {0}, valid_c[9][9] = {0}, valid_h[9][9] = {0};
        for (int r = 0; r < board.size(); r ++) {
            for (int c = 0; c < board[r].size(); c ++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0' - 1;
                    int k = r / 3 * 3 + c / 3;
                    if (valid_r[r][num] || valid_c[c][num] || valid_h[k][num])
                        return false;
                    valid_r[r][num] = valid_c[c][num] = valid_h[k][num] = 1;
                }
            }
        }
        return true;
    }
};