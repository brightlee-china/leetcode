class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int lo = 0, hi = len - 1;
        vector<int> result;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) 
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        int low = lo;
        if (low > len - 1 || nums[low] != target) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        lo = 0; hi = len - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target)
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
        int up = lo;
        result.push_back(low);
        result.push_back(up - 1);
        return result;
    }
};