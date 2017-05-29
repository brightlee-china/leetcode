class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int lo = -1;
        int hi = len - 1;
        int i = 0;
        while (i <= hi) {
            if (nums[i] == 0)
                swap(nums[++ lo], nums[i ++]);
            else if (nums[i] == 2)
                swap(nums[hi --], nums[i]);
            else 
                i ++;
        }
    }
};