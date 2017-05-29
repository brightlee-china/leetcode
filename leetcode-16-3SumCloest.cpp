class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = (1 << 31) - 1;
        int result = 0;
        
        for (int i = 0; i < nums.size(); i ++) {
            int temp = nums[i];
            int lo = i + 1, hi = nums.size() - 1;
            while (lo < hi) {
                int a = nums[lo];
                int b = nums[hi];
                
                int abc = temp + a + b;
                int dis = abs(target - abc);
                if (dis == 0) {
                    return target;
                }
                else if (dis < closest) {
                    closest = dis;
                    result = abc;
                }
                
                if (abc < target) {
                    lo ++;
                }
                else {
                    hi --;
                }
            }
        }
        
        return result;
    }
};