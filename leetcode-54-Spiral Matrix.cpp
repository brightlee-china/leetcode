class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty())
            return result;
            
        int n = matrix[0].size();
        int m = matrix.size();
        
        int r = n - 1, l = 0, u = 0, d = m - 1;
        while (true) {
            for (int i = l; i <= r; i ++) 
                result.push_back(matrix[u][i]);
            if (++ u > d)
                break;
            for (int i = u; i <= d; i ++)
                result.push_back(matrix[i][r]);
            if (-- r < l)
                break;
            for (int i = r; i >= l; i --) 
                result.push_back(matrix[d][i]);
            if (-- d < u)
                break;
            for (int i = d; i >= u; i --) 
                result.push_back(matrix[i][l]);
            if (++ l > r)
                break;
        }
        
        return result;
    }
}; 