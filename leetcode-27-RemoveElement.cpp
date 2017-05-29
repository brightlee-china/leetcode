class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                nums[cnt ++] = nums[i];
            }
        }
        
        return cnt;
    }
};