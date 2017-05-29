class Solution {
public:
    string longestPalindrome(string s) {
        int from = 0, to = 0;
        int result = 0;
        for (int i = 0; i < s.length(); i ++) {
            // odd
            for (int j = 1; i + j < s.length(), i - j >=0; j ++) {
                if (s[i - j] != s[i + j]) {
                    break;
                }

                if (result < j * 2 + 1) {
                    from = i - j;
                    to = i + j;
                    result = j * 2 + 1;
                }
            }

            // even
            for (int j = 0; i + j + 1 < s.length(), i - j >= 0; j ++) {
                if (s[i + j + 1] != s[i - j]) {
                    break;
                }

                if (result < 2 * j + 2) {
                    from = i - j;
                    to = i + j + 1;
                    result = j * 2 + 2;
                }
            }
        }

        return s.substr(from, to - from + 1);
    }
};