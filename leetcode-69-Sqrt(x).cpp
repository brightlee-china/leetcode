class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        
        int lo = 1, hi = x;
        int mid, ans;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (mid <= x / mid) {
                lo = mid + 1;
                ans = mid;
            }
            else 
                hi = mid - 1;
        }
        
        return ans;
    }
};