class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        for (int i = 0; i <= (1 << len) - 1; i ++) {
            vector<int> cur;
            int index = 0;
            for (int j = i; j > 0; j /= 2, index ++) {
                if (j % 2 != 0) 
                    cur.push_back(nums[index]);
            }
            
            result.push_back(cur);
        }
        
        return result;
    }
};