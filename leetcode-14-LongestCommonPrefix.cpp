class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int i = 0; strs.size() >= 1 && i < strs[0].length(); i ++) {
            char cur = strs[0][i];
            bool flg = true;
            for (int j = 1; j < strs.size(); j ++) {
                if (i >= strs[j].length() || cur != strs[j][i]) {
                    flg = false;
                    return result;
                }
            }
            
            if (flg)
                result += cur;
        }
        
        return result;
    }
};