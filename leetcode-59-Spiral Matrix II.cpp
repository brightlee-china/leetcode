class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int tot = 1;
        vector<vector<int>> result(n, vector<int>(n));
        
        int l = 0, r = n - 1, u = 0, d = n - 1;
        while (true) {
            for (int i = l; i <= r; i ++) result[u][i] = tot ++;
            if (++ u > d) break;
            for (int i = u; i <= d; i ++) result[i][r] = tot ++;
            if (-- r < l) break;
            for (int i = r; i >= l; i --) result[d][i] = tot ++;
            if (-- d < u) break;
            for (int i = d; i >= u; i --) result[i][l] = tot ++;
            if (++ l > r) break;
        }
        
        return result;
    }
};