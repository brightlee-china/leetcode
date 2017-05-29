class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int *dp = new int[len];
        int maxL = 0;
        dp[0] = 0;
        
        for (int i = 1; i < len; i ++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') 
                    dp[i] = (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                else 
                    dp[i] = 0;
                
                maxL = max(dp[i], maxL);
            }
            else 
                dp[i] = 0;
        }
        return maxL;
    }    
    
};