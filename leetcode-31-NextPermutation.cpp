class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 1;
        for (; i > 0; i --) {
            if (nums[i - 1] < nums[i]) {
                int j = len - 1;
                for (; j > i - 1; j --) {
                    if (nums[j] > nums[i - 1]) 
                        break;
                }
                
                int temp = nums[i - 1];
                nums[i - 1] = nums[j];
                nums[j] = temp;
                
                reverse(nums.begin() + i, nums.end());
                return ;
            }
        }
        
        reverse(nums.begin(), nums.end());
    }
};