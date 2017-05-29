class Solution {
public:
    void solve(vector<vector<string>> &result, vector<string> &cur, int index, int n, int *vis_c, int *vis_slash, int *vis_b_slash) {
        if (index >= n) {
            result.push_back(cur);
            return ;
        }
        
        for (int c = 0; c < n; c ++) {
            if (!vis_c[c] && !vis_slash[index + c] && !vis_b_slash[index - c + n]) {
                vis_c[c] = 1;
                vis_slash[index + c] = 1;
                vis_b_slash[index - c + n] = 1;
                string temp(n, '.');
                temp[c] = 'Q';
                cur.push_back(temp);
                solve(result, cur, index + 1, n, vis_c, vis_slash, vis_b_slash);
                cur.pop_back();
                vis_c[c] = 0;
                vis_slash[index + c] = 0;
                vis_b_slash[index - c + n] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int *vis_c = new int[n];
        int *vis_slash = new int[2 * n];
        int *vis_b_slash = new int[2 * n];
        
        memset(vis_c, 0, sizeof(int) * n);
        memset(vis_slash, 0, sizeof(int) * 2 * n);
        memset(vis_b_slash, 0, sizeof(int) * 2 * n);
        
        vector<vector<string>> result;
        vector<string> cur;
    
        solve(result, cur, 0, n, vis_c, vis_slash, vis_b_slash);
        return result;
    }
};