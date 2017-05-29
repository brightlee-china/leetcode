class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();

        bool *valid = new bool[(len_s+1) * (len_p+1)];
        memset(valid, false, sizeof(bool) * (len_s + 1) * (len_p + 1));
        valid[0] = true;
        
        for (int j = 1; j <= len_p; j ++) {
            if (p[len_p - j + 1] == '*') {
                valid[j] = valid[j - 2];
            }
        }

        for (int i = 1; i <= len_s; i ++) {
            for (int j = 1; j <= len_p; j ++) {
                if (p[len_p - j + 1] == '*') {
                    if (p[len_p - j] == s[len_s - i] || p[len_p - j] == '.')
                        valid[i * (len_p+1) + j] = valid[(i - 1) * (len_p+1) + j] || valid[i * (len_p+1) + j - 2] || valid[(i - 1) * (len_p+1) + j - 2];
                    else
                        valid[i * (len_p+1) + j] = valid[i * (len_p+1) + j - 2];
                }
                else {
                    if (p[len_p - j] == s[len_s - i] || p[len_p - j] == '.')
                        valid[i * (len_p+1) + j] = valid[(i-1) * (len_p+1) + j - 1];
                    else
                        valid[i * (len_p+1) + j] = false;
                }
            }
        }

        return valid[len_s * (len_p+1) + len_p];
    }
};