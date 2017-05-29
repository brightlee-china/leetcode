class Solution {
public:
    void solve(vector<vector<int>> &result, vector<int> &cur, int pos, vector<int> &nums) {
        result.push_back(cur);
        for (int i = pos; i < nums.size(); i ++) {
            if (i != pos && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            solve(result, cur, i + 1, nums); // 记住是下一个
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> cur;
        solve(result, cur, 0, nums);
        
        return result;
    }
};