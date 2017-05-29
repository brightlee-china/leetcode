class Solution {
public:
    void solve(int *vis_c, int *vis_slash, int *vis_b_slash, int n, int index, int& cnt) {
        if (index >= n) {
            cnt ++;
            return;
        }
        
        for (int c = 0; c < n; c ++) {
            if (!vis_c[c] && !vis_slash[c + index] && !vis_b_slash[index - c + n]) {
                vis_c[c] = 1;
                vis_slash[index + c] = 1;
                vis_b_slash[index - c + n] = 1;
                solve(vis_c, vis_slash, vis_b_slash, n, index + 1, cnt);
                vis_c[c] = 0;
                vis_slash[index + c] = 0;
                vis_b_slash[index - c + n] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        int *vis_c = new int[n];
        int *vis_slash = new int[n * 2];
        int *vis_b_slash = new int[n * 2];
        
        memset(vis_c, 0, sizeof(int) * n);
        memset(vis_slash, 0, sizeof(int) * 2 * n);
        memset(vis_b_slash, 0, sizeof(int) * 2 * n);
        
        int cnt = 0;
        solve(vis_c, vis_slash, vis_b_slash, n, 0, cnt);
        return cnt;
    }
};