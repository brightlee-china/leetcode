class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int target = -nums[i];
            int lo = i + 1, hi = nums.size() - 1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] < target)
                    lo ++;
                else if (nums[lo] + nums[hi] > target)
                    hi --;
                else {
                    vector<int> temp(3, 0);
                    temp[0] = nums[i];
                    temp[1] = nums[lo];
                    temp[2] = nums[hi];
                    result.push_back(temp);
                    
                    while (lo < hi && nums[lo] == temp[1])
                        lo ++;
                    while (lo < hi && nums[hi] == temp[2])
                        hi --;
                }
            }
            
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i ++;
        }
        
        return result;
    }
};