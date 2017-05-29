class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        vector<int> stk;
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;
        for (int r = 0; r < n; r ++) {
            matrix[r].push_back('0');
            stk.clear();
            for (int c = 0; c <= m; c ++) {
                int f = r == 0 ? 0 : matrix[r - 1][c] - '0';
                matrix[r][c] = matrix[r][c] == '0' ? '0' : f + matrix[r][c];
                while (stk.size() > 0 && matrix[r][stk.back()] >= matrix[r][c]) {
                    int h = matrix[r][stk.back()] - '0';
                    stk.pop_back();
                    int index = stk.size() > 0 ? stk.back() : -1;
                    if (h * (c - index - 1) > result)
                        result = h * (c - index - 1);
                }
                stk.push_back(c);
            }
        }
        
        return result;
    }
};