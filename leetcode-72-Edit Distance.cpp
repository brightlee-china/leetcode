class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int *dp = new int[(len1 + 1) * (len2 + 1)];
        memset(dp, 0, sizeof(int) * (len1 + 1) * (len2 + 1));
        int col = len2 + 1;
        
        
        dp[0 * col + 0] = 0;
        for (int i = 1; i <= len1; i ++)
            dp[i * col + 0] = i;
        for (int j = 1; j <= len2; j ++)
            dp[0 * col + j] = j;
        
        for (int i = 1; i <= len1; i ++) {
            for (int j = 1; j <= len2; j ++) {
                int a = INT_MAX;
                int b = INT_MAX;
                if (word1[i - 1] == word2[j - 1])
                    a = dp[(i - 1) * col + j - 1];
                else
                    a = dp[(i - 1) * col + j - 1] + 1;

                b = min(dp[(i - 1) * col + j] + 1, dp[i * col + j - 1] + 1);
                dp[i * col + j] = min(a, b);
            }
        }
        
        return dp[len1 * col + len2];
    }
};