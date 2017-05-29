class Solution {
public:
    int solve(vector<vector<int>> &dp, int from, int to) {
        if (from == to) {
            dp[from][to] = 1;
            return 1;
        }
        
        if (dp[from][to])
            return dp[from][to];
        dp[from][to] = solve(dp, from + 1, to);
        for (int i = from + 1; i < to; i ++) {
            int left = solve(dp, from, i - 1);
            int right = solve(dp, i + 1, to);
            dp[from][to] += left * right;
        }
        dp[from][to] += solve(dp, from, to - 1);
        return dp[from][to];
    }

    int numTrees(int n) {
        vector<vector<int>>dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return solve(dp, 1, n);
    }
};