class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int start = 0;
        vector<int> t(256, -1);
        
        for (int i = 0; i < s.length(); i ++) {
            if (t[s[i]] > start)
                start = t[s[i]];
            t[s[i]] = i + 1;
            result = max(result, i - start + 1);
        }
        
        return result;
    }
};