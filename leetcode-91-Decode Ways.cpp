class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        int len = s.size();
        vector<int> dp(len + 1, 0);
        dp[len - 1] = s[len - 1] == '0' ? 0 : 1;
        dp[len] = 1;
        
        for (int i = len - 2; i >= 0; i --) {
            if (s[i] == '0') {
                dp[i] = 0;
            }
            else if((s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                dp[i] += dp[i + 2];
                dp[i] += dp[i + 1];
            }
            else 
                dp[i] = dp[i + 1];
            
        }
        
        return dp[0];
    }
};