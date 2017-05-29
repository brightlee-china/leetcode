class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // from back to front 
        int first = m - 1;
        int second = n - 1;
        int cnt = m + n - 1;
        while (first >= 0 && second >= 0) {
            if (nums1[first] > nums2[second])
                nums1[cnt --] = nums1[first --];
            else 
                nums1[cnt --] = nums2[second --];
        }
        
        // if nums2 not empty, than the left numbers must be smallest.
        while (second >= 0)
            nums1[cnt --] = nums2[second --];
    }
};