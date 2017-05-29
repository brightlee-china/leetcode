class Solution {
public:
    void solve(vector<vector<int>> &result, vector<int> &cur, int k, int cnt, vector<int> &vis, int n, int front) {
        if (cnt == k) {
            result.push_back(cur);
            return;
        }
        
        for (int i = front + 1; i <= n; i ++) {
            if (vis[i - 1] == 0) {
                vis[i - 1] = 1;
                cur.push_back(i);
                solve(result, cur, k, cnt + 1, vis, n, i);
                vis[i - 1] = 0;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> vis(n, 0);
        vector<vector<int>> result;
        vector<int> cur;
        solve(result, cur, k, 0, vis, n, 0);
        return result;
    }
};