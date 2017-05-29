class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int len = s.length();
        int i = len - 1;
        while (s[i] == '.' || s[i] == ' ') 
            i --;
        for (; i >= 0; i --, cnt ++) {
            if (s[i] == '.' || s[i] == ' ')
                break;
        }
        
        return cnt;
    }
};