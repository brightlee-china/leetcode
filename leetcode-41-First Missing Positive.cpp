class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0)
            return 1;
        
        for (int i = 0; i < nums.size(); i ++) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        int j = 0;
        for (; j < nums.size(); j ++) {
            if (nums[j] != j + 1)
                return j + 1;
        }
        
        return nums[j - 1] + 1;
    }
};