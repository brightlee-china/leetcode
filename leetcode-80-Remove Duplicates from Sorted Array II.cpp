class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int end = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                nums[end ++] = nums[i];
                cnt = 1;
            }
            else {
                if (cnt > 0) {
                    nums[end ++] = nums[i];
                    cnt --;
                }
            }
        }
        
        return end;
    }
};