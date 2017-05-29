class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int lo = 0, hi = len - 1;
        int mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) 
                hi = mid - 1;
            else if (nums[mid] < target) 
                lo = mid + 1;
            else 
                break;
        }
        
        if (nums[mid] == target)
            return mid;
        return lo;
    }
};