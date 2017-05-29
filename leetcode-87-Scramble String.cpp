class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        
        if (s1.size() != s2.size()) 
            return false;
        
        vector<int> cnt(26, 0);
        for (int i = 0; i < s1.size(); i ++) {
            cnt[s1[i] - 'a'] ++;
            cnt[s2[i] - 'a'] --;
        }
        
        for (int i = 0; i < 26; i ++)
            if (cnt[i])
                return false;
        
        int len = s1.size();
        for (int i = 1; i < len; i ++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
                return true;
        }
        
        return false;
    }
};