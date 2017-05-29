class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        int end = 0;
        while (true) {
            int cur = end;
            for (int i = start; i <= end; i ++) {
                cur = max(cur, nums[i] + i);
            }
            
            if (cur >= len - 1) 
                return true;
            else if (cur == end)
                return false;
            
            start = end + 1;
            end = cur;
        }
    }
};