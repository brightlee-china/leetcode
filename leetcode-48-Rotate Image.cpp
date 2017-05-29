class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size() - 1;
        for (int c = 0; c <= N / 2; c ++) {
            for (int r = c; r + c < N; r ++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[N - c][r];
                matrix[N - c][r] = matrix[N - r][N - c];
                matrix[N - r][N - c] = matrix[c][N - r];
                matrix[c][N - r] = temp;
            }
        }
    }
};