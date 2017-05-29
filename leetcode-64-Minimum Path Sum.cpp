class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dp(m, 0);
        dp[0] = grid[0][0];
        for (int i = 1; i < m; i ++) {
            dp[i] = grid[i][0] + dp[i - 1];
        }
        
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (j == 0) 
                    dp[j] = grid[j][i] + dp[j];
                else {
                    dp[j] = grid[j][i] + min(dp[j], dp[j - 1]);
                }
            }
        }
        
        return dp[m - 1];    
    }
};