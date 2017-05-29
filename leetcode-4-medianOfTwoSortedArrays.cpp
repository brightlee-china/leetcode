class Solution {
public:
    double getkth(vector<int>& A, int from_A, int m, vector<int>& B, int from_B, int n, int k) {
        if (m > n) 
            return getkth(B, from_B, n, A, from_A, m, k);
        if (m == 0)
            return B[from_B + k - 1];
        if (k == 1)
            return min(A[from_A], B[from_B]);
        
        int i = min(m, k / 2), j = min(n, k / 2);
        if (A[from_A + i - 1] > B[from_B + j - 1])
            return getkth(A, from_A, m, B, from_B + j, n - j, k - j);
        else
            return getkth(A, from_A + i, m - i, B, from_B, n, k - i);
        
        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int l = (m + n + 1) / 2;
        int r = (m + n + 2) / 2;
        return (getkth(nums1, 0, m, nums2, 0, n, l) + getkth(nums1, 0, m, nums2, 0, n, r)) / 2.0;
    }
};