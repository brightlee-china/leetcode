class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                int t = target - nums[i] - nums[j];
                int lo = j + 1, hi = nums.size() - 1;
                while (lo < hi) {
                    int a = nums[lo];
                    int b = nums[hi];
                    if (a + b < t) 
                        lo ++;
                    else if (a + b > t)
                        hi --;
                    else {
                        vector<int> temp(4, 0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = a;
                        temp[3] = b;
                        result.push_back(temp);
                        
                        while (lo < hi && nums[lo] == a) lo ++;
                        while (lo < hi && nums[hi] == b) hi --;
                    }
                }
                
                while (j + 3 < nums.size() && nums[j] == nums[j + 1]) j ++;
            }
            
            while (i + 4 < nums.size() && nums[i] == nums[i + 1]) i ++;
        }
        
        return result;
    }
};