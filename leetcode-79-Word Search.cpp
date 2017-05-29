class Solution {
public:
    int solve(vector<vector<char>> &board, string &word, int x, int y, int index, vector<vector<int>> &vis) {
        if (!vis[x][y] && board[x][y] == word[index]) {
            // find in four directions
            int flg = 0;
            vis[x][y] = 1;
            if (index + 1 == word.size())
                return 1;
            
            if (x > 0)
                flg |= solve(board, word, x - 1, y, index + 1, vis);
            if (y > 0)
                flg |= solve(board, word, x, y - 1, index + 1, vis);
            if (x < board.size() - 1)
                flg |= solve(board, word, x + 1, y, index + 1, vis);
            if (y < board[0].size() - 1)
                flg |= solve(board, word, x, y + 1, index + 1, vis);
            
            vis[x][y] = flg;
            return flg;
        }
        
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (solve(board, word, i, j, 0, vis))
                    return true;
            }
        }
        
        return false;
    }
};