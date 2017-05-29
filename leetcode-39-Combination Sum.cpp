class Solution {
private:
    void solve(vector<vector<int>>& res, vector<int>& cur, int target, vector<int>& candidates, int from) {
        if (target == 0) {
            res.push_back(cur);
            return ;
        }
        
        if (target < 0) {
            return ;
        }
        
        for (int i = from; i < candidates.size(); i ++) {
            if (target >= candidates[i]) {
                cur.push_back(candidates[i]);
                solve(res, cur, target - candidates[i], candidates, i);
                cur.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> cur;
        solve(result, cur, target, candidates, 0);
        return result;
    }
};