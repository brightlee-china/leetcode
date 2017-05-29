class Solution {
private:
    void solve(vector<vector<int>>& result, vector<int>& candidates, vector<int>& cur, int target, int begin) {
        if (target == 0) {
            result.push_back(cur);
            return;
        }
        
        if (target < 0)
            return;
        
        if (begin == candidates.size())
            return;
        
        int chosen = -1;
        for (int i = begin; i < candidates.size(); i ++) {
            if (target >= candidates[i]) {
                if (chosen == candidates[i])
                    continue;
                
                chosen = candidates[i];
                cur.push_back(candidates[i]);
                solve(result, candidates, cur, target - candidates[i], i + 1);
                cur.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int > cur;
        solve(result, candidates, cur, target, 0);
        return result;
    }
};