class Solution {
public:
    int strStr(string haystack, string needle) {
        int N = haystack.length();
        int M = needle.length();
        int i, j;
        for (i = 0; i + M <= N; i ++) {
            for (j = 0; j < M; j ++) {
                if (needle[j] != haystack[i + j])
                    break;
            }
            
            if (j == M)
                return i;
        }
        
        return -1;
    }
};