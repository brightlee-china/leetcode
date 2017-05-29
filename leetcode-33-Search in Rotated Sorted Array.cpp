class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) 
            return -1;
        if (nums[0] > nums[len - 1]) {
            int lo = 0, hi = len - 1;
            if (target <= nums[hi]) {
                int mid;
                while (lo <= hi) {
                    mid = lo + (hi - lo) / 2;
                    if (nums[mid] > nums[len - 1]) {
                        lo = mid + 1;
                        continue;
                    }
                    
                    if (target > nums[mid]) 
                        lo = mid + 1;
                    else if (target < nums[mid])
                        hi = mid - 1;
                    else 
                        break;
                }
                
                if (nums[mid] == target)
                    return mid;
                else 
                    return -1;
                
            }
            else if (target >= nums[0]) {
                int mid;
                while (lo <= hi) {
                    mid = lo + (hi - lo) / 2;
                    if (nums[mid] < nums[len - 1]) {
                        hi = mid - 1;
                        continue;
                    }
                    
                    if (target > nums[mid]) 
                        lo = mid + 1;
                    else if (target < nums[mid])
                        hi = mid - 1;
                    else 
                        break;
                }
                
                if (nums[mid] == target)
                    return mid;
                else 
                    return -1;
            }
            else 
                return -1;
        }
        else {
            int lo = 0, hi = len - 1;
            int mid;
            while (lo <= hi) {
                mid = lo + (hi - lo) / 2;
                if (nums[mid] < target) 
                    lo = mid + 1;
                else if (nums[mid] > target)
                    hi = mid - 1;
                else 
                    break;
            }
            
            if (nums[mid] == target)
                return mid;
            else 
                return -1;
        }
    }
};