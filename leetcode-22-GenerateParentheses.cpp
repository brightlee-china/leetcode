class Solution {
public:
    void addP(vector<string>& result, string v, int n, int m) {
        if (n == 0 && m == 0) {
            result.push_back(v);
            return;
        }
        
        if (n > 0) 
            addP(result, v + "(", n - 1, m + 1);
        if (m > 0)
            addP(result, v + ")", n, m - 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addP(result, "", n, 0);
        return result;
    }
};