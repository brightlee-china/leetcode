class Solution {
public:
    bool isMatch(string s, string p) {
        int match, asterisk = -1;
        int i = 0, j = 0;
        int len_s = s.length();
        int len_p = p.length();
        while (i < len_s) {
            if (j < len_p && p[j] == '*') {
                match = i;
                asterisk = j ++;
            }
            else if (j < len_p && p[j] == '?' || p[j] == s[i]) {
                i ++;
                j ++;
            }
            else if (asterisk >= 0) {
                i = ++ match;
                j = asterisk + 1;
            }
            else 
                return false;
        }
        
        while (j < len_p && p[j] == '*') j ++;
        return j == len_p;
    }
};