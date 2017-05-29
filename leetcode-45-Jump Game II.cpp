class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0;
        int step = 0;
        int N = nums.size();
        while (end < N - 1) {
            step ++;
            int maxend = end + 1;
            for (int i = start; i <= end; i ++) {
                if (nums[i] + i >= N - 1)
                    return step;
                
                maxend = max(maxend, nums[i] + i);
            }
            
            start = end + 1;
            end = maxend;
        }
        
        return step;
    }
};