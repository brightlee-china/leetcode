class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (obstacleGrid[j][i])
                    dp[j][i] = 0;
                else if (i == 0 && j == 0)
                    dp[j][i] = 1;
                else if (j == 0) 
                    dp[j][i] = dp[j][i - 1];
                else if (i == 0)
                    dp[j][i] = dp[j - 1][i];
                else 
                    dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};