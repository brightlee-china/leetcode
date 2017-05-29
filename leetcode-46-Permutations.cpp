class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& result, int *vis, vector<int>& cur, int index) {
        if (index >= nums.size()) {
            result.push_back(cur);
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (!vis[i]) {
                cur.push_back(nums[i]);
                vis[i] = 1;
                solve(nums, result, vis, cur, index + 1);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        int *vis = new int[len];
        memset(vis, 0, sizeof(int) * len);
        vector<vector<int>> result;
        vector<int> cur;

        solve(nums, result, vis, cur, 0);
        return result;
    }

};