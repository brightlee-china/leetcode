class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& nums, vector<int>& cur, int *vis, int index) {
        if (index >= nums.size()) {
            result.push_back(cur);
            return;
        }
        
        int chosen = INT_MAX;
        for (int i = 0; i < nums.size(); i ++) {
            if (!vis[i] && nums[i] != chosen) {
                chosen = nums[i];
                vis[i] = 1;
                cur.push_back(nums[i]);
                solve(result, nums, cur, vis, index + 1);
                cur.pop_back();
                vis[i] = 0;
            }
        }
        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        int *vis = new int[nums.size()];
        memset(vis, 0, sizeof(int) * nums.size());
        
        solve(result, nums, cur, vis, 0);
        return result;
    }
};